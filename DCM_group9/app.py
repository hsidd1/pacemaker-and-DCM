"""Main application program for the DCM application.

This file contains all the screens of the application including
the welcome screen, homepage screen, settings screen and pacing
parameters display screen.
"""
import tkinter as tk
from PIL import ImageTk, Image
from database import Database
from backend import Backend
from user import User
from screens import Screen, WelcomeScreen, HomepageScreen, SettingsScreen
from application_fsm import ApplicationFSM

class Application:

    def __init__(self, run: bool = True):
        """Initialises the application with a database and backend object.
        :param database: Database object for storing user data
        :param backend: Backend object for communicating with the pacemaker
        :param current_user: User object for the current user logged in
        :param page_geometry: String of the current pages geometry
        :param windowed_maximized: Boolean of whether the window is maximized or not
        :param run: Boolean of whether the application should run or not"""
        self.database: Database = Database()
        self.backend: Backend = Backend()
        self.current_user: User | None = None
        self.page_geometry: str = "600x500"
        self.windowed_maximized: bool = False
        self.run: bool = run
        self.settings_screen = SettingsScreen(self.page_geometry, self.current_user)


    def run_app(self):
        while(self.run):
            self.welcome_screen = WelcomeScreen(self.page_geometry)
            self.welcome_screen.run_screen()
            if(self.welcome_screen.login):
                self.homepage_screen = HomepageScreen(self.welcome_screen.geometry, self.welcome_screen.logged_user)
                self.homepage_screen.run_screen()
            tk._exit()

    def welcome_screentest(self) -> None:
        """Welcome page for login and registration of users"""
        welcome_page = tk.Tk()
        welcome_page.title("DCM Application - Welcome Page")
        welcome_page.geometry(self.page_geometry)
        welcome_page.configure(bg="#8a8d91")

        tk.Label(
            welcome_page,
            text="Pacemaker Device Controller-Monitor",
            font=("Helvetica", 25, "bold"),
            background="#8a8d91",
        ).pack(pady=10)

        self.bring_to_front(welcome_page)

        # username labels
        username_label = tk.Label(
            welcome_page, text="Username:", background="#8a8d91", font=("Helvetica", 12)
        )
        username_label.pack(pady=4)

        # username entry
        username_entry = tk.Entry(welcome_page, text="username")
        username_entry.pack(pady=1)
        username_entry.focus_set()

        # password labels
        password_label = tk.Label(
            welcome_page, text="Password:", background="#8a8d91", font=("Helvetica", 12)
        )
        password_label.pack()

        # password entry
        password_entry = tk.Entry(welcome_page, text="password", show="*")
        password_entry.pack()

        def register_user() -> None:
            """wrapper for Database.register_user() for button command"""
            self.database.register_user(
                welcome_page=welcome_page,
                username_entry=username_entry,
                password_entry=password_entry,
            )

        def login_user() -> None:
            """wrapper for Database.login_user() for button command.
            takes user to homepage_screen() if successful"""

            # Username and password input (username is case insensitive)
            current_username = username_entry.get().lower()
            current_password = username_entry.get()

            # Check if login is valid otherwise return
            is_valid = self.database.login_user(
                welcome_page=welcome_page,
                username_entry=username_entry,
                password_entry=password_entry,
            )
            if not is_valid:
                return
            
            users = self.database.read_from_file()

            # Update current_user using User class
            self.current_user = User(
                current_username,
                current_password,
                users[0][current_username]["pacing_mode_params"],
            )

            self.page_geometry = welcome_page.geometry()

            welcome_page.destroy()
            self.homepage_screen()

        # Login and register buttons
        login_btn = tk.Button(
            welcome_page, text="Login", width=10, height=1, bg="#eda758", command=login_user
        )
        login_btn.pack(pady=10)
        register_btn = tk.Button(
            welcome_page,
            text="Register",
            width=10,
            height=1,
            bg="#eda758",
            command=register_user,
        )

        welcome_page.bind('<Return>', lambda event: login_user())

        register_btn.pack()

        # Image logo
        logo = Image.open("DCM_group9/imgs/heartLogo.png")
        logo_resized = logo.resize((100, 100))
        logo_resized = ImageTk.PhotoImage(logo_resized)
        logo_label = tk.Label(welcome_page, image=logo_resized, background="#8a8d91")
        logo_label.pack(side="bottom", pady=50)

        welcome_page.mainloop()


    def homepage_screentest(self) -> None:
        """Homepage screen for choosing pacing mode and viewing pacing data.
        Takes User to pacing_display_screen() when all parameters are filled in"""
        homepage_screen = tk.Tk()
        homepage_screen.title("DCM Application - Home Page")
        homepage_screen.geometry(self.page_geometry)
        homepage_screen.configure(bg="#8a8d91")
        homepage_screen.columnconfigure(0, weight=1)
        homepage_screen.columnconfigure(1, weight=1)
        homepage_screen.columnconfigure(2, weight=1)
        hompage_title_label = tk.Label(
            homepage_screen,
            text="Pacemaker Device Controller-Monitor",
            font=("Helvetica", 25, "bold"),
            background="#8a8d91",
        )
        hompage_title_label.grid(row=0, column=0, columnspan=20, pady=10)
        
        self.bring_to_front(homepage_screen)

        # --------------- page features ------------------ #
        # Dropdown menu to choose pacing mode
        pacing_mode_label = tk.Label(
            homepage_screen,
            text="Choose pacing mode:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        pacing_mode_label.grid(row=1, column=0, pady=10)
        default = "Select a Pacing Mode"
        pacing_mode = tk.StringVar(homepage_screen)
        pacing_mode.set(default)  # default value
        pacing_mode_dropdown = tk.OptionMenu(
            homepage_screen, pacing_mode, "AOO", "AAI", "VOO", "VVI"
        )
        pacing_mode_dropdown.config(width=len(default))
        pacing_mode_dropdown.grid(row=1, column=1, pady=2, sticky='EW')

        # get input into a variable (test this)
        # pacing_mode_input = pacing_mode.get()

        settings_btn = tk.Button(
            homepage_screen,
            text="Settings",
            width=10,
            height=1,
            bg="#eda758",
            command=lambda: get_pacing_mode(),
        )
        settings_btn.grid(row=1, column=2, pady=2)

        def get_pacing_mode() -> None:
            """Gets pacing mode from dropdown menu and calls settings_screen() 
            for that pacing mode. Used as a wrapper for Settings button command"""
            self.page_geometry = homepage_screen.geometry()

            pacing_mode_input = pacing_mode.get()

            if (pacing_mode_input == "Select a Pacing Mode"):
                # Incorrect password
                num_columns = 3
                column_size = homepage_screen.winfo_width()/num_columns
                message = tk.Label(
                    homepage_screen,
                    text="Please select a valid pacing mode",
                    fg="red",
                    background="#8a8d91",
                    font=("calibri", 11, "bold"),
                    wraplength=column_size-2,
                ).grid(row=10, column=1, pady=2)
                return

            homepage_screen.destroy()
            self.settings_screen(pacing_mode_input)

        def logout() -> None:
            """Logs user out and takes them back to welcome page.
            Destroys homepage_screen. Used as a wrapper for Logout button command"""
            self.page_geometry = homepage_screen.geometry()

            homepage_screen.destroy()
            self.welcome_screen()

        back_btn = tk.Button(
            homepage_screen, text="Logout", width=10, height=1, bg="#eda758", command=logout
        )

        def egram() -> None:
            """Takes user to egram screen"""
            self.page_geometry = homepage_screen.geometry()

            homepage_screen.destroy()
            self.egram_screen()

        egram_btn = tk.Button(
            homepage_screen, text="View Egram", width=10, height=1, bg="#eda758", command=egram
        )

        egram_btn.grid(row=15, column=0, pady=10)
        back_btn.grid(row=15, column=1, pady=10)
        
        homepage_screen.bind('<Escape>', lambda event: logout())

        # Connection Status
        if self.backend.is_connected:
            text = "Connection status: Connected"
        else:
            text = "Connection status: Disconnected"
        status_label = tk.Label(
            homepage_screen,
            text=text,
            background="#00FF00" if self.backend.is_connected else "red",
            font=("Helvetica", 10, "bold"),
        )
        status_label.grid(row=12, column=0, pady=10)
        
        # Board Connected ID (known or unknown)
        if self.backend.board_connected:
            if self.backend.device_id in self.backend.previous_device_ids:
                text = f"ID: {self.backend.board_connected} (Known Device)"
                color = "green"
            else:
                text = f"ID: {self.backend.board_connected} (Unknown Device)"
                color = "red"
        else:
            text = "ID: None (Known Status Unavailable)"
            color = "grey"
        board_label = tk.Label(
            homepage_screen,
            text=text,
            background=color,
            font=("Helvetica", 10, "bold"),
        )
        board_label.grid(row=12, column=1, pady=10)

    def egram_screen(self) -> None:
        egram_screen = tk.Tk()
        egram_screen.geometry(self.page_geometry)
        egram_screen.title("DCM Application - Egram")
        egram_screen.configure(bg="#8a8d91")
        self.bring_to_front(egram_screen)

        def back() -> None:
            """Takes user back to homepage"""
            self.page_geometry = egram_screen.geometry()

            egram_screen.destroy()
            self.homepage_screen()

        back_btn = tk.Button(
            egram_screen, text="Back", width=10, height=1, bg="#eda758", command=back
        )
        back_btn.grid(row=0, column=0, pady=10, padx=10, sticky='W')
        egram_screen.bind('<Escape>', lambda event: back())


    def settings_screentest(self, pacing_mode: str) -> None:
        """Settings screen for changing pacing mode parameters.
        Takes User to pacing_display_screen() when all parameters are filled in"""
        settings_screen = tk.Tk()
        settings_screen.geometry(self.page_geometry)
        settings_screen.title("DCM Application - Pacing Mode Settings")
        # settings_screen.geometry("600x500")
        settings_screen.configure(bg="#8a8d91")
        settings_title_label = tk.Label(
            settings_screen,
            text="Pacing Mode Settings",
            font=("Helvetica", 25, "bold"),
            background="#8a8d91",
        )
        settings_title_label.grid(row=0, column=0, columnspan=20, pady=10)
        self.bring_to_front(settings_screen)        

        # Labels and entries for pacing mode parameters
        LowerRate_label = tk.Label(
            settings_screen,
            text="Lower Rate Limit:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        LowerRate_entry = tk.Entry(settings_screen)

        UpperRate_label = tk.Label(
            settings_screen,
            text="Upper Rate Limit:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        UpperRate_entry = tk.Entry(settings_screen)

        AtrialAmp_label = tk.Label(
            settings_screen,
            text="Atrial Amplitude:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        AtrialAmp_entry = tk.Entry(settings_screen)

        AtrialPulseWidth_label = tk.Label(
            settings_screen,
            text="Atrial Pulse Width:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        AtrialPulseWidth_entry = tk.Entry(settings_screen)

        VentricularAmp_label = tk.Label(
            settings_screen,
            text="Ventricular Amplitude:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        VentricularAmp_entry = tk.Entry(settings_screen)

        VentricularPulseWidth_label = tk.Label(
            settings_screen,
            text="Ventricular Pulse Width:",
            background="#8a8d91",
            font=("Helvetica", 10),
        )
        VentricularPulseWidth_entry = tk.Entry(settings_screen)

        Vrp_label = tk.Label(
            settings_screen, text="VRP:", background="#8a8d91", font=("Helvetica", 10)
        )
        Vrp_entry = tk.Entry(settings_screen)

        Arp_label = tk.Label(
            settings_screen, text="ARP:", background="#8a8d91", font=("Helvetica", 10)
        )
        Arp_entry = tk.Entry(settings_screen)
        
        LowerRate_entry.focus_set()

        def apply():
            """Applies the pacing mode parameters to the current_user"""
            param_data = {
                "l_rate_limit": LowerRate_entry.get(),
                "u_rate_limit": UpperRate_entry.get(),
                "atrial_amplitude": AtrialAmp_entry.get(),
                "atrial_pulse_width": AtrialPulseWidth_entry.get(),
                "ARP": Arp_entry.get(),
                "vent_amplitude": VentricularAmp_entry.get(),
                "vent_pulse_width": VentricularPulseWidth_entry.get(),
                "VRP": Vrp_entry.get(),
            }

            # Remove empty parameters
            temp_data = dict(param_data)
            for key in temp_data:
                if not len(temp_data[key]):
                    del param_data[key]
            self.database.update_parameters(
                self.current_user, self.current_user.username, pacing_mode, param_data
            )

        def ok():
            """Do both apply and close, similar features to Windows settings"""
            apply()
            close()

        def close():
            """Closes the settings screen"""
            self.page_geometry = settings_screen.geometry()

            settings_screen.destroy()
            self.homepage_screen()

        apply_btn = tk.Button(
            settings_screen, text="Apply", width=10, height=1, bg="#eda758", command=apply
        )
        ok_btn = tk.Button(
            settings_screen, text="OK", width=10, height=1, bg="#eda758", command=ok
        )
        close_btn = tk.Button(
            settings_screen, text="Close", width=10, height=1, bg="#eda758", command=close
        )

        settings_screen.bind('<Return>', lambda event: ok())
        settings_screen.bind('<Escape>', lambda event: close())

        def display_parameters_layout(type: str) -> None:
            """Displays the standard parameters for the pacing mode type provided"""
            LowerRate_label.grid(row=1, column=0, columnspan=2, pady=2)
            LowerRate_entry.grid(row=1, column=2, pady=2)
            UpperRate_label.grid(row=2, column=0, columnspan=2, pady=2)
            UpperRate_entry.grid(row=2, column=2, pady=2)
            if type == "A":
                # AOO and AAI pacing mode
                AtrialAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
                AtrialAmp_entry.grid(row=1, column=10, pady=2)
                AtrialPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
                AtrialPulseWidth_entry.grid(row=2, column=10, pady=2)
                apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
                ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
                close_btn.grid(row=3, column=4, columnspan=2, pady=10)
            elif type == "V":
                # VOO and VVI pacing mode
                VentricularAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
                VentricularAmp_entry.grid(row=1, column=10, pady=2)
                VentricularPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
                VentricularPulseWidth_entry.grid(row=2, column=10, pady=2)
                apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
                ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
                close_btn.grid(row=3, column=4, columnspan=2, pady=10)
            else:
                raise ValueError("Invalid pacing mode type")
        
        if pacing_mode == "AOO":
            display_parameters_layout("A")
            apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
            ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
            close_btn.grid(row=3, column=4, columnspan=2, pady=10)

            LowerRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["l_rate_limit"])
            UpperRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["u_rate_limit"])
            AtrialAmp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["atrial_amplitude"])
            AtrialPulseWidth_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["atrial_pulse_width"])

        elif pacing_mode == "VOO":
            display_parameters_layout("V")
            apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
            ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
            close_btn.grid(row=3, column=4, columnspan=2, pady=10)

            LowerRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["l_rate_limit"])
            UpperRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["u_rate_limit"])
            VentricularAmp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["vent_amplitude"])
            VentricularPulseWidth_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["vent_pulse_width"])        
        elif pacing_mode == "VVI":
            display_parameters_layout("V")
            Vrp_label.grid(row=3, column=0, columnspan=2, pady=2)
            Vrp_entry.grid(row=3, column=2, pady=2, columnspan=1)
            apply_btn.grid(row=4, column=0, columnspan=2, pady=10)
            ok_btn.grid(row=4, column=2, columnspan=2, pady=10)
            close_btn.grid(row=4, column=4, columnspan=2, pady=10)

            LowerRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["l_rate_limit"])
            UpperRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["u_rate_limit"])
            VentricularAmp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["vent_amplitude"])
            VentricularPulseWidth_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["vent_pulse_width"])        
            Vrp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["VRP"])     
        elif pacing_mode == "AAI":
            display_parameters_layout("A")
            Arp_label.grid(row=3, column=0, columnspan=2, pady=2)
            Arp_entry.grid(row=3, column=2, pady=2, columnspan=1)
            apply_btn.grid(row=4, column=0, columnspan=2, pady=10)
            ok_btn.grid(row=4, column=2, columnspan=2, pady=10)
            close_btn.grid(row=4, column=4, columnspan=2, pady=10)

            LowerRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["l_rate_limit"])
            UpperRate_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["u_rate_limit"])
            AtrialAmp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["atrial_amplitude"])
            AtrialPulseWidth_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["atrial_pulse_width"])
            Arp_entry.insert(0, self.current_user.parameter_dict[pacing_mode]["ARP"])

    @staticmethod
    def bring_to_front(screen: tk):
        """Brings screen to front"""
        screen.lift()
        screen.attributes('-topmost',True)
        screen.after_idle(screen.attributes,'-topmost',False)
        screen.focus_force()



    def pacing_display_screen(self):
        """Screen for displaying pacing data"""
        pass


if __name__ == "__main__":
    app = ApplicationFSM()
    app.run_app()
