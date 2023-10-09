import tkinter as tk
from PIL import ImageTk, Image
from database import Database
from backend import Backend
from user import User

Database = Database()
Backend = Backend()

# The current_user that is logged in
current_user = None


def welcome_screen():
    """Welcome page for login and registration of users"""
    welcome_page = tk.Tk()
    welcome_page.title("DCM Application - Welcome Page")
    welcome_page.geometry("600x500")
    welcome_page.configure(bg="#8a8d91")
    # welcome_page.attributes('-fullscreen', True)

    tk.Label(
        welcome_page,
        text="Pacemaker Device Controller-Monitor",
        font=("Helvetica", 25, "bold"),
        background="#8a8d91",
    ).pack(pady=10)

    # username labels
    username_label = tk.Label(
        welcome_page, text="Username:", background="#8a8d91", font=("Helvetica", 12)
    )
    username_label.pack(pady=4)

    # username entry
    username_entry = tk.Entry(welcome_page, text="username")
    username_entry.pack(pady=1)

    # password labels
    password_label = tk.Label(
        welcome_page, text="Password:", background="#8a8d91", font=("Helvetica", 12)
    )
    password_label.pack()

    # password entry
    password_entry = tk.Entry(welcome_page, text="password", show="*")
    password_entry.pack()

    def register_user():
        """wrapper for Database.register_user()"""
        Database.register_user(
            welcome_page=welcome_page,
            username_entry=username_entry,
            password_entry=password_entry,
        )

    def login_user():
        """wrapper for Database.login_user()
        takes user to homepage_screen() if successful"""
        global current_user
        current_username = username_entry.get()
        current_password = username_entry.get()
        is_valid = Database.login_user(
            welcome_page=welcome_page,
            username_entry=username_entry,
            password_entry=password_entry,
            homepage_screen=homepage_screen,
        )
        if not is_valid:
            return
        users = Database.read_from_file()

        current_user = User(
            current_username,
            current_password,
            users[0][current_username]["pacing_mode_params"],
        )

    # Log in and register buttons
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
    register_btn.pack()

    # Image logo
    logo = Image.open("DCM_group9/imgs/heartLogo.png")
    # maximum size to be able to still display three error messages on screen
    logo_resized = logo.resize((100, 100))
    logo_resized = ImageTk.PhotoImage(logo_resized)
    logo_label = tk.Label(welcome_page, image=logo_resized, background="#8a8d91")
    logo_label.pack(side="bottom", pady=50)

    welcome_page.mainloop()


def homepage_screen():
    """Homepage screen for choosing pacing mode and viewing pacing data
    Takes User to pacing_display_screen() when all parameters are filled in"""
    # configuring the page attributes
    homepage_screen = tk.Tk()
    homepage_screen.title("DCM Application - Home Page")
    homepage_screen.geometry("600x500")
    homepage_screen.configure(bg="#8a8d91")
    hompage_title_label = tk.Label(
        homepage_screen,
        text="Pacemaker Device Controller-Monitor",
        font=("Helvetica", 25, "bold"),
        background="#8a8d91",
    )
    hompage_title_label.grid(row=0, column=0, columnspan=20, pady=10)

    # --------------- page features ------------------ #
    # dropdown menu to choose pacing mode
    pacing_mode_label = tk.Label(
        homepage_screen,
        text="Choose pacing mode:",
        background="#8a8d91",
        font=("Helvetica", 10),
    )
    pacing_mode_label.grid(row=1, column=0, columnspan=2, pady=2)
    pacing_mode = tk.StringVar(homepage_screen)
    pacing_mode.set("")  # default value
    pacing_mode_dropdown = tk.OptionMenu(
        homepage_screen, pacing_mode, "AOO", "AAI", "VOO", "VVI"
    )
    pacing_mode_dropdown.grid(row=1, column=2, pady=2)
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
    settings_btn.grid(row=1, column=3, pady=2)

    def get_pacing_mode():
        pacing_mode_input = pacing_mode.get()
        settings_screen(pacing_mode_input)

    # Button to go back to welcome page at bottom left
    def logout():
        """Logs user out and takes them back to welcome page
        destroys homepage_screen"""
        homepage_screen.destroy()
        welcome_screen()

    back_btn = tk.Button(
        homepage_screen, text="Logout", width=10, height=1, bg="#eda758", command=logout
    )
    back_btn.grid(row=10, column=0, pady=10)
    # Connection Status
    if Backend.is_connected:
        text = "Connection status: Connected"
    else:
        text = "Connection status: Disconnected"
    status_label = tk.Label(
        homepage_screen,
        text=text,
        background="#00FF00" if Backend.is_connected else "red",
        font=("Helvetica", 10, "bold"),
    )
    status_label.grid(row=13, column=0, pady=10)


def settings_screen(pacing_mode: str):
    settings_screen = tk.Tk()
    settings_screen.geometry("520x350")
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

    def apply():
        # TODO: update all parameters in database
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

        temp_data = dict(param_data)
        for key in temp_data:
            if not len(temp_data[key]):
                del param_data[key]
        Database.update_parameters(
            current_user, current_user.username, pacing_mode, param_data
        )

    def ok():
        # apply and close
        apply()
        close()

    def close():
        settings_screen.destroy()

    apply_btn = tk.Button(
        settings_screen, text="Apply", width=10, height=1, bg="#eda758", command=apply
    )
    ok_btn = tk.Button(
        settings_screen, text="OK", width=10, height=1, bg="#eda758", command=ok
    )
    close_btn = tk.Button(
        settings_screen, text="Close", width=10, height=1, bg="#eda758", command=close
    )

    if pacing_mode == "AOO":
        LowerRate_label.grid(row=1, column=0, columnspan=2, pady=2)
        LowerRate_entry.grid(row=1, column=2, pady=2)
        UpperRate_label.grid(row=2, column=0, columnspan=2, pady=2)
        UpperRate_entry.grid(row=2, column=2, pady=2)
        AtrialAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
        AtrialAmp_entry.grid(row=1, column=10, pady=2)
        AtrialPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
        AtrialPulseWidth_entry.grid(row=2, column=10, pady=2)
        apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
        ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
        close_btn.grid(row=3, column=4, columnspan=2, pady=10)
    elif pacing_mode == "VOO":
        LowerRate_label.grid(row=1, column=0, columnspan=2, pady=2)
        LowerRate_entry.grid(row=1, column=2, pady=2)
        UpperRate_label.grid(row=2, column=0, columnspan=2, pady=2)
        UpperRate_entry.grid(row=2, column=2, pady=2)
        VentricularAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
        VentricularAmp_entry.grid(row=1, column=10, pady=2)
        VentricularPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
        VentricularPulseWidth_entry.grid(row=2, column=10, pady=2)
        apply_btn.grid(row=3, column=0, columnspan=2, pady=10)
        ok_btn.grid(row=3, column=2, columnspan=2, pady=10)
        close_btn.grid(row=3, column=4, columnspan=2, pady=10)
    elif pacing_mode == "VVI":
        LowerRate_label.grid(row=1, column=0, columnspan=2, pady=2)
        LowerRate_entry.grid(row=1, column=2, pady=2)
        UpperRate_label.grid(row=2, column=0, columnspan=2, pady=2)
        UpperRate_entry.grid(row=2, column=2, pady=2)
        VentricularAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
        VentricularAmp_entry.grid(row=1, column=10, pady=2)
        VentricularPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
        VentricularPulseWidth_entry.grid(row=2, column=10, pady=2)
        Vrp_label.grid(row=3, column=0, columnspan=2, pady=2)
        Vrp_entry.grid(row=3, column=2, pady=2, columnspan=1)
        apply_btn.grid(row=4, column=0, columnspan=2, pady=10)
        ok_btn.grid(row=4, column=2, columnspan=2, pady=10)
        close_btn.grid(row=4, column=4, columnspan=2, pady=10)
    elif pacing_mode == "AAI":
        LowerRate_label.grid(row=1, column=0, columnspan=2, pady=2)
        LowerRate_entry.grid(row=1, column=2, pady=2)
        UpperRate_label.grid(row=2, column=0, columnspan=2, pady=2)
        UpperRate_entry.grid(row=2, column=2, pady=2)
        AtrialAmp_label.grid(row=1, column=4, columnspan=2, pady=2)
        AtrialAmp_entry.grid(row=1, column=10, pady=2)
        AtrialPulseWidth_label.grid(row=2, column=4, columnspan=2, pady=2)
        AtrialPulseWidth_entry.grid(row=2, column=10, pady=2)
        Arp_label.grid(row=3, column=0, columnspan=2, pady=2)
        Arp_entry.grid(row=3, column=2, pady=2, columnspan=1)
        apply_btn.grid(row=4, column=0, columnspan=2, pady=10)
        ok_btn.grid(row=4, column=2, columnspan=2, pady=10)
        close_btn.grid(row=4, column=4, columnspan=2, pady=10)


def pacing_display_screen():
    pass


def main():
    welcome_screen()
    # homepage_screen() # for testing, skip login


if __name__ == "__main__":
    main()
    tk._exit()
