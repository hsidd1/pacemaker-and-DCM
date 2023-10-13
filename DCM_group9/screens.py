import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from backend import Backend
from database import Database
from user import User
from pacing_parameters import Parameters
from custom_widgets import FunkyWidget


class Screen:
    def __init__(self, geometry: str, bg_colour: str = "#8a8d91"):
        self.bg_colour = bg_colour
        self.geometry = geometry
        self.screen: tk.Tk = None
        self.widgets = {
            "Button": [],
            "Entry": [],
            "Label": [],
            "OptionMenu": [],
            "FunkyWidget": [],
        }
        self.page_width = 0
        self.page_height = 0
        self.num_columns = 0
        self.num_rows = 0

    def create_button(
        self,
        text: str,
        command: callable,
        width: int = 10,
        height: int = 1,
        bg_colour: str = "#eda758",
    ):
        button = tk.Button(
            self.screen,
            text=text,
            width=width,
            height=height,
            bg=bg_colour,
            command=command,
        )
        self.widgets["Button"].append(button)
        return button

    def create_entry(self, encrypted: bool = False):
        if encrypted:
            entry = tk.Entry(self.screen, show="*")
        else:
            entry = tk.Entry(self.screen)
        self.widgets["Entry"].append(entry)
        return entry

    def create_label(
        self,
        text: str,
        fontsize: int,
        bold: bool = False,
        font: str = "Helvetica",
        wraplength: int = 0,
    ):
        if bold:
            input_font = (font, fontsize, "bold")
        else:
            input_font = (font, fontsize)
        label = tk.Label(
            self.screen,
            text=text,
            font=input_font,
            background="#8a8d91",
            wraplength=wraplength,
        )
        self.widgets["Label"].append(label)
        return label

    def create_options(self, options: list, default_text: str = None):
        string = tk.StringVar(self.screen)
        if default_text:
            string.set(default_text)
        dropdown = ttk.Combobox(
            self.screen, textvariable=string, values=options, state="readonly"
        )
        self.widgets["OptionMenu"].append(dropdown)
        return dropdown, string

    def create_funky_widget(self, entry_map: dict, data: str):
        funky_widget = FunkyWidget(self.screen, entry_map, data)
        self.widgets["FunkyWidget"].append(funky_widget)
        return funky_widget

    def create_logo(self, image_path: str, dimensions: tuple):
        logo = Image.open(image_path)
        logo_resized = logo.resize(dimensions)
        logo_resized = ImageTk.PhotoImage(logo_resized)
        logo_label = self.create_label("", 0)  # Empty label to hold image
        logo_label.configure(image=logo_resized)
        logo_label.image = logo_resized
        return logo_label

    def create_spacer(self, space: int):
        spacer = tk.Frame(self.screen, height=space, bg=self.bg_colour)
        return spacer

    def bring_to_front(self):
        """Brings screen to front"""
        self.screen.lift()
        self.screen.attributes("-topmost", True)
        self.screen.after_idle(self.screen.attributes, "-topmost", False)
        self.screen.focus_force()

    def load_grid(self, cols: bool, rows: bool):
        if cols:
            for i in range(0, self.num_columns):
                self.screen.columnconfigure(i, weight=1, uniform="cols_group")
        if rows:
            for i in range(0, self.num_rows):
                self.screen.rowconfigure(i, weight=1, uniform="row_group")

    def prepare_screen_switch(self):
        self.geometry = self.screen.geometry()
        self.close_screen()

    def run_screen(self):
        self.screen = tk.Tk()
        self.screen.geometry(self.geometry)
        self.screen.configure(bg=self.bg_colour)
        self.screen.update()
        self.page_height = self.screen.winfo_height()
        self.page_width = self.screen.winfo_width()
        self.rows, self.columns = self.screen.grid_size()
        self.bring_to_front()

    def close_screen(self) -> None:
        self.screen.destroy()


class WelcomeScreen(Screen):
    def __init__(self, geometry: str, bg_colour: str = "#8a8d91"):
        """Only the WelcomeScreen and SettingsScreen should have access to database !!!
        USE THE CURRENTUSER IN HomePage!!!!!!"""
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Welcome Page"
        self.database = Database()
        self.logged_in = False
        self.logged_user = None

    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        super().create_label("Pacemaker Device Controller-Monitor", 25, True).pack(
            pady=10
        )
        super().create_label("Username", 12).pack(pady=4)
        super().create_entry().pack()
        super().create_label("Password", 12).pack()
        super().create_entry(True).pack()
        super().create_button("Login", self.login_user).pack(pady=10)
        super().create_button("Register", self.register_user).pack()
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).pack(
            side="bottom", pady=50
        )
        self.screen.bind("<Return>", lambda event: self.login_user())
        self.screen.mainloop()

    def login_user(self) -> User:
        """wrapper for Database.login_user() for button command.
        takes user to homepage_screen() if successful"""

        # Username and password input (username is case insensitive)
        current_username = self.widgets["Entry"][0].get().lower()
        current_password = self.widgets["Entry"][1].get()

        # Check if login is valid otherwise return
        is_valid = self.database.login_user(
            welcome_page=self.screen,
            username_entry=self.widgets["Entry"][0],
            password_entry=self.widgets["Entry"][1],
        )

        if not is_valid:
            self.login = False
            return None

        users = self.database.read_from_file()
        # Update current_user using User class
        self.logged_user = User(
            current_username,
            current_password,
            users[0][current_username]["pacing_mode_params"],
        )

        self.logged_in = True
        super().prepare_screen_switch()

    def register_user(self) -> None:
        """wrapper for Database.register_user() for button command"""
        self.database.register_user(
            welcome_page=self.screen,
            username_entry=self.widgets["Entry"][0],
            password_entry=self.widgets["Entry"][1],
        )


class HomepageScreen(Screen):
    def __init__(self, geometry: str, current_user: User, bg_colour: str = "#8a8d91"):
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Home Page"
        self.current_user = current_user
        self.pacing_mode = None
        self.num_columns = 3
        self.logged_out = False
        self.egram_view = False
        self.settings_view = False
        self.backend = Backend()
        self.pacing_modes = ["AOO", "AAI", "VOO", "VVI", "AOOR", "VOOR", "AAIR", "VVIR"]

    def run_screen(self):
        super().run_screen()
        super().load_grid(True, False)
        self.screen.title(self.title)
        super().create_label("Pacemaker Device Controller-Monitor", 25, True).grid(
            row=0, column=0, columnspan=20, pady=10
        )
        super().create_label("Choose pacing mode:", 10).grid(row=1, column=0, pady=10)
        default = "Select a Pacing Mode"
        dropdown = super().create_options(self.pacing_modes, default)
        pacing_mode_dropdown = dropdown[0]
        self.pacing_mode = dropdown[1]
        pacing_mode_dropdown.config(width=len(default))
        pacing_mode_dropdown.grid(row=1, column=1, pady=2, sticky="EW")

        super().create_button("Settings", self.get_pacing_mode).grid(
            row=1, column=2, pady=2
        )
        super().create_button("Logout", self.logout).grid(row=15, column=1, pady=10)
        super().create_button("View Egram", self.egram).grid(row=15, column=0, pady=10)
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).grid(
            row=16, column=0, columnspan=20, pady=50
        )

        self.check_connection()
        self.screen.mainloop()

    def get_pacing_mode(self) -> None:
        """Gets pacing mode from dropdown menu and calls settings_screen()
        for that pacing mode. Used as a wrapper for Settings button command"""

        pacing_mode_input = self.pacing_mode.get()

        if pacing_mode_input == "Select a Pacing Mode":
            # Incorrect password
            column_size = self.screen.winfo_width() / self.num_columns
            super().create_label(
                "Please select a valid pacing mode",
                11,
                True,
                "calibri",
                column_size - 2,
            ).grid(row=10, column=1, pady=2)
            return
        else:
            self.pacing_mode = pacing_mode_input
            self.settings_view = True
            super().prepare_screen_switch()

    def logout(self) -> None:
        """Logs user out"""
        self.logged_out = True
        self.geometry = self.screen.geometry()
        self.close_screen()

    def egram(self) -> None:
        """Takes user to egram screen"""
        self.egram_view = True
        super().prepare_screen_switch()

    def check_connection(self):
        if self.backend.is_connected:
            text = "Connection status: Connected"
        else:
            text = "Connection status: Disconnected"
        status_label = tk.Label(
            self.screen,
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
            self.screen,
            text=text,
            background=color,
            font=("Helvetica", 10, "bold"),
        )
        board_label.grid(row=12, column=1, pady=10)


class SettingsScreen(Screen):
    def __init__(
        self,
        geometry: str,
        current_user: User,
        pacing_mode: str,
        bg_colour: str = "#8a8d91",
    ):
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Pacing Mode Settings"
        self.current_user = current_user
        self.pacing_mode = pacing_mode
        self.pacing_modes_map = {
            "AOO": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.ATRIAL_AMPLITUDE,
                Parameters.ATRIAL_PULSE_WIDTH,
            ],
            "AAI": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.ATRIAL_AMPLITUDE,
                Parameters.ATRIAL_PULSE_WIDTH,
                Parameters.ARP,
            ],
            "VOO": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.VENTRICULAR_AMPLITUDE,
                Parameters.VENTRICULAR_PULSE_WIDTH,
            ],
            "VVI": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.VENTRICULAR_AMPLITUDE,
                Parameters.VENTRICULAR_PULSE_WIDTH,
                Parameters.VRP,
            ],
            "AOOR": [],
            "AAIR": [],
            "VOOR": [],
            "VVIR": [],
        }
        self.num_columns = 5
        self.num_rows = 4
        self.last_row = (
            4 * len(self.pacing_modes_map.get(pacing_mode, None)) // self.num_columns
        )
        self.closed = False
        self.database = Database()

    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        self.load_grid(True, False)
        parameters = self.pacing_modes_map.get(self.pacing_mode, None)
        print(parameters[0].value.name)

        for i, param in enumerate(parameters):
            super().create_label(f"{param.value.name} ({param.value.unit})", 10).grid(
                row=(i // self.num_columns + i // self.num_columns),
                column=i % self.num_columns,
                padx=5,
                pady=5,
            )
            super().create_funky_widget(
                param.value.valid_interval_map,
                self.current_user.parameter_dict.get(self.pacing_mode)[
                    param.value.name
                ],
            ).grid(
                row=(i // self.num_columns + i // self.num_columns) + 1,
                column=i % self.num_columns,
            )

        super().create_spacer(30).grid(row=self.last_row, column=0)

        super().create_button("Apply", self.apply).grid(row=self.last_row + 1, column=0)
        super().create_button("Ok", self.ok).grid(row=self.last_row + 1, column=1)
        super().create_button("Close", self.close).grid(row=self.last_row + 1, column=2)
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).grid(
            row=self.last_row + 2, column=0, columnspan=20, pady=50
        )

        self.screen.mainloop()

    def apply(self):
        param_map = self.pacing_modes_map[self.pacing_mode]
        param_data = {param.value.name: "" for param in param_map}

        for funky, param in zip(self.widgets["FunkyWidget"], param_data):
            param_data[param] = funky.get

        self.database.update_parameters(
            self.current_user, self.current_user.username, self.pacing_mode, param_data
        )

    def ok(self):
        """Do both apply and close, similar features to Windows settings"""
        self.apply()
        self.closed = True
        self.prepare_screen_switch()

    def close(self):
        self.closed = True
        self.prepare_screen_switch()


class EgramScreen(Screen):
    def __init__(self, geometry: str, bg_colour: str = "#8a8d91"):
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Egram"

    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).pack(
            side="bottom", pady=50
        )

        self.screen.mainloop()
