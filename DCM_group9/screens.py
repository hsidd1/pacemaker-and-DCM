"""Contains the screens for the DCM app."""
from __future__ import annotations

import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from functools import partial
from backend.backend import Backend
from backend.database import Database
from user import User
from utils.pacing_parameters import Parameters
from utils.custom_widgets import FunkyWidget
from ui_config.config import AccessibilityConfig
from multiprocessing import shared_memory
import serial

import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

import numpy as np


class Screen:
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        bg_colour: str = "#8a8d91",
    ):
        """Initializes Screen class with geometry and background colour.
        :param geometry: geometry of the screen
        :param bg_colour: background colour of the screen
        """
        self.accessibility_config = accessibility_config
        self.bg_colour = bg_colour
        self.geometry = geometry
        self.screen: tk.Tk = None
        #self.buf = shared_memory.SharedMemory(name="dee", create=False, size=1024)
        self.widgets = {
            "Button": [],
            "Entry": [],
            "Label": [],
            "OptionMenu": [],
            "FunkyWidget": [],
            "Scale": [],
        }
        self.page_width = 0
        self.page_height = 0
        self.num_columns = 0
        self.num_rows = 0
        self.title = ""
        self.column_size = 0
        self.config = accessibility_config

    def create_button(
        self,
        text: str,
        command: callable,
        width: int = 10,
        height: int = 1,
        bg_colour: str = "#eda758",
    ) -> tk.Button:
        """Creates a button widget with command and returns it."""
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

    def create_entry(self, encrypted: bool = False) -> tk.Entry:
        """Creates an entry widget and returns it."""
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
        fg: str = "black",
        bg: str = "#8a8d91",
    ) -> tk.Label:
        """Creates a label widget and returns it."""
        if bold:
            input_font = (font, fontsize, "bold")
        else:
            input_font = (font, fontsize)
        label = tk.Label(
            self.screen,
            text=text,
            font=input_font,
            fg=fg,
            background="#8a8d91",
            wraplength=wraplength,
            bg=bg,
        )
        self.widgets["Label"].append(label)
        return label

    def create_options(self, options: list, default_text: str = None) -> tuple:
        """Creates an option menu widget and returns it."""
        string = tk.StringVar(self.screen)
        if default_text:
            string.set(default_text)
        dropdown = ttk.Combobox(
            self.screen, textvariable=string, values=options, state="readonly"
        )
        self.widgets["OptionMenu"].append((dropdown, string))
        return dropdown, string

    def create_funky_widget(self, entry_map: dict, data: str) -> FunkyWidget:
        """Creates a funky widget and returns it."""
        funky_widget = FunkyWidget(self.screen, entry_map, data)
        self.widgets["FunkyWidget"].append(funky_widget)
        return funky_widget

    def create_logo(self, image_path: str, dimensions: tuple) -> tk.Label:
        """Creates a logo widget and returns it."""
        logo = Image.open(image_path)
        logo_resized = logo.resize(dimensions)
        logo_resized = ImageTk.PhotoImage(logo_resized)
        logo_label = self.create_label("", 0)  # Empty label to hold image
        logo_label.configure(image=logo_resized)
        logo_label.image = logo_resized
        return logo_label

    def create_spacer(self, space: int) -> tk.Frame:
        """Creates a spacer widget and returns it."""
        spacer = tk.Frame(self.screen, height=space, width=space, bg=self.bg_colour)
        return spacer

    def bring_to_front(self) -> None:
        """Brings screen to front"""
        self.screen.lift()
        self.screen.attributes("-topmost", True)
        self.screen.after_idle(self.screen.attributes, "-topmost", False)
        self.screen.focus_force()

    def load_grid(self, cols: bool, rows: bool, uniform: bool = False) -> None:
        if cols:
            for i in range(0, self.num_columns):
                self.screen.columnconfigure(
                    i, weight=1, uniform="cols_group" if uniform else ""
                )
        if rows:
            for i in range(0, self.num_rows):
                self.screen.rowconfigure(
                    i, weight=1, uniform="row_group" if uniform else ""
                )

    def prepare_screen_switch(self) -> None:
        self.geometry = self.screen.geometry()
        self.close_screen()

    def run_screen(self) -> None:
        """Creates screen with geometry and background colour."""
        self.screen = tk.Tk()
        self.screen.geometry(self.geometry)
        self.screen.configure(bg=self.bg_colour)
        self.screen.update()
        self.page_height = self.screen.winfo_height()
        self.page_width = self.screen.winfo_width()
        self.rows, self.columns = self.screen.grid_size()
        self.screen.title(self.title)
        self.bring_to_front()
        self.screen.bind("<Configure>", self.update_column_size)

    def close_screen(self) -> None:
        self.screen.destroy()

    def update_column_size(self, event):
        if self.num_columns:
            self.column_size = self.screen.winfo_width() / self.num_columns
        else:
            self.column_size = self.screen.winfo_width()


class WelcomeScreen(Screen):
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        bg_colour: str = "#8a8d91",
    ):
        """
        Initializes WelcomeScreen class with geometry and background colour.
        :param geometry: geometry of the screen
        :param bg_colour: background colour of the screen

        Only the WelcomeScreen and SettingsScreen should have access to database !!!
        USE THE CURRENTUSER IN HomePage!!!!!!"""
        super().__init__(geometry, accessibility_config, bg_colour)
        self.title = "DCM Application - Welcome Page"
        self.database = Database()
        self.logged_in = False
        self.view_settings = False
        self.logged_user = None

    def run_screen(self) -> None:
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
        super().create_button("Settings", self.open_settings).place(
            x=20, y=self.screen.winfo_height() - 45
        )
        self.screen.bind("<Return>", lambda event: self.login_user())
        self.screen.bind("<Configure>", self.update)
        self.screen.mainloop()

    def update(self, event):
        self.widgets["Button"][2].place(x=20, y=self.screen.winfo_height() - 45)

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

    def open_settings(self):
        self.view_settings = True
        super().prepare_screen_switch()


class AccessibilitySettingsScreen(Screen):
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        bg_colour: str = "#8a8d91",
    ):
        super().__init__(geometry, accessibility_config, bg_colour)
        self.title = "DCM Application - Accessibility Settings"
        self.config = accessibility_config
        self.settings = accessibility_config.get_settings()
        self.num_rows = 4
        self.closed = False

    def run_screen(self):
        super().run_screen()
        super().load_grid(True, True, True)
        super().create_label(list(self.settings[0].keys())[0], 10).grid(
            row=0, column=0, padx=5
        )
        super().create_options(
            self.settings[0][list(self.settings[0].keys())[0]], self.config.colour_mode
        )[0].grid(row=0, column=1)
        super().create_spacer(100).grid(row=0, column=2)

        red = tk.Label(
            self.screen,
            width=6,
            height=3,
            bg=self.config.colour_map[self.config.colour_mode][0],
        )
        green = tk.Label(
            self.screen,
            width=6,
            height=3,
            bg=self.config.colour_map[self.config.colour_mode][1],
        )
        red.grid(row=0, column=3)
        green.grid(row=0, column=4)

        scale = tk.Scale(
            self.screen,
            from_=self.settings[1][list(self.settings[1].keys())[0]][0],
            to_=self.settings[1][list(self.settings[1].keys())[0]][1],
            orient="horizontal",
            label="Font Size",
        )
        scale.grid(row=1, column=0, columnspan=2)
        scale.set(self.config.font_size)
        self.widgets["Scale"].append(scale)
        self.widgets["Label"].append(red)
        self.widgets["Label"].append(green)

        self.create_label("Hello World!", self.config.font_size).grid(
            row=1, column=2, columnspan=4
        )

        super().create_button("Apply", self.apply).grid(row=2, column=0, columnspan=2)
        super().create_button("Ok", self.ok).grid(row=2, column=2, padx=20)
        super().create_button("Close", self.close).grid(row=2, column=5)
        self.screen.mainloop()

    def apply(self):
        font_size = int(self.widgets["Scale"][0].get())
        colour_mode = self.widgets["OptionMenu"][0][0].get()

        self.config.font_size = font_size
        self.config.colour_mode = colour_mode

        self.widgets["Label"][3].configure(font=("Helvetica", self.config.font_size))
        self.widgets["Label"][1].configure(bg=self.config.colour_map[colour_mode][0])
        self.widgets["Label"][2].configure(bg=self.config.colour_map[colour_mode][1])

    def close(self):
        self.closed = True
        self.prepare_screen_switch()

    def ok(self):
        self.apply()
        self.close()


class HomepageScreen(Screen):
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        current_user: User,
        backend: Backend,
        bg_colour: str = "#8a8d91",
    ):
        """Initializes HomepageScreen class with geometry, current user and background colour."""
        super().__init__(geometry, accessibility_config, bg_colour)
        self.title = "DCM Application - Home Page"
        self.current_user = current_user
        self.pacing_mode = None
        self.config = accessibility_config
        self.num_columns = 3
        self.logged_out = False
        self.egram_view = False
        self.settings_view = False
        self.backend = backend
        self.pacing_modes = ["AOO", "AAI", "VOO", "VVI", "AOOR", "VOOR", "AAIR", "VVIR"]

    def run_screen(self) -> None:
        super().run_screen()
        super().load_grid(True, False)
        self.screen.title(self.title)
        super().create_label("Pacemaker Device Controller-Monitor", 25, True).grid(
            row=0, column=0, columnspan=20, pady=10
        )

        self.screen.update()

        super().create_label(
            "Choose pacing mode:", self.config.font_size, wraplength=self.column_size
        ).grid(row=1, column=0, pady=10)
        default = "Select a Pacing Mode"
        dropdown = super().create_options(self.pacing_modes, default)
        pacing_mode_dropdown = dropdown[0]
        self.pacing_mode = dropdown[1]
        pacing_mode_dropdown.config(width=len(default))
        pacing_mode_dropdown.grid(row=1, column=1, pady=2, sticky="EW")

        super().create_button("Settings", self.get_pacing_mode).grid(
            row=1, column=2, pady=2
        )
        super().create_button("Logout", self.logout).grid(row=15, column=2, pady=10)
        super().create_button("View Egram", self.egram).grid(row=15, column=0, pady=10)
        super().create_button("Send Data", self.send_data).grid(row=15, column=1, pady=10)
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).grid(
            row=16, column=0, columnspan=20, pady=50
        )

        self.screen.bind("<Escape>", lambda event: self.logout())

        self.check_connection()
        self.screen.mainloop()

    def get_pacing_mode(self) -> None:
        """Gets pacing mode from dropdown menu and calls settings_screen()
        for that pacing mode. Used as a wrapper for Settings button command"""

        pacing_mode_input = self.pacing_mode.get()

        if pacing_mode_input == "Select a Pacing Mode":
            # Incorrect password
            # column_size = self.screen.winfo_width() / self.num_columns
            try:
                self.widgets["Label"].pop(2).destroy()
            except IndexError:
                pass
            applied = super().create_label(
                "Please select a valid pacing mode",
                11,
                True,
                "calibri",
                self.column_size - 2,
            )
            applied.grid(row=10, column=1, pady=2)
            destroy_applied_msg = partial(applied.destroy)
            try:
                self.pending_after_id = self.screen.after(2000, destroy_applied_msg)
            except tk.TclError:
                pass

            return
        else:
            self.pacing_mode = pacing_mode_input
            self.settings_view = True
            super().prepare_screen_switch()

    def logout(self) -> None:
        """Logs user out"""
        self.logged_out = True
        super().prepare_screen_switch()

    def egram(self) -> None:
        """Takes user to egram screen"""
        self.egram_view = True
        super().prepare_screen_switch()

    def check_connection(self) -> None:
        """Checks connection status from backend and displays it on the screen."""
        try:
            self.widgets["Label"].pop(2).destroy()
            self.widgets["Label"].pop(3).destroy()
        except IndexError:
            pass
        
        if self.backend.is_connected:
            text = "Connection status: Connected"
        else:
            text = "Connection status: Disconnected"
        status_label = tk.Label(
            self.screen,
            text=text,
            background=self.config.colour_map[self.config.colour_mode][1]
            if self.backend.is_connected
            else self.config.colour_map[self.config.colour_mode][0],
            font=("Helvetica", 10, "bold"),
        )
        status_label.grid(row=12, column=0, pady=10)

        self.widgets["Label"].append(status_label)

        # Board Connected ID (known or unknown)
        if self.backend.ser.is_open:
            text = "ID: Pacemaker Board"
        else:
            text = "ID: None (Known Status Unavailable)"
            color = "grey"
        board_label = tk.Label(
            self.screen,
            text=text,
            background=self.config.colour_map[self.config.colour_mode][1]
            if self.backend.is_connected
            else self.config.colour_map[self.config.colour_mode][0],
            font=("Helvetica", 10, "bold"),
        )
        board_label.grid(row=12, column=1, pady=10)

        self.widgets["Label"].append(board_label)

        self.screen.after(1000, self.check_connection)
    
    def send_data(self):
        pacing_mode = self.widgets["OptionMenu"][0][1].get()
        if pacing_mode == "Select a Pacing Mode":
            return
        self.backend.transmit_parameters(pacing_mode, self.current_user.parameter_dict[pacing_mode])     



class SettingsScreen(Screen):
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        current_user: User,
        pacing_mode: str,
        bg_colour: str = "#8a8d91",
    ):
        """Initializes SettingsScreen class with geometry, current user, pacing mode and background colour."""
        super().__init__(geometry, accessibility_config, bg_colour)
        self.title = "DCM Application - Pacing Mode Settings"
        self.current_user = current_user
        self.pacing_mode = pacing_mode
        # TODO: update R type modes in assignment 2
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
                Parameters.ATRIAL_SENSITIVITY,
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
                Parameters.VENTRICULAR_SENSITIVITY,
                Parameters.VRP,
            ],
            "AOOR": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.ATRIAL_AMPLITUDE_REGULATED,
                Parameters.ATRIAL_PULSE_WIDTH,
                Parameters.REACTION_TIME,
                Parameters.RESPONSE_FACTOR,
                Parameters.RECOVERY_TIME,
            ],
            "AAIR": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.ATRIAL_AMPLITUDE_REGULATED,
                Parameters.ATRIAL_PULSE_WIDTH,
                Parameters.ARP,
                Parameters.ATRIAL_SENSITIVITY,
                Parameters.REACTION_TIME,
                Parameters.RESPONSE_FACTOR,
                Parameters.RECOVERY_TIME,
            ],
            "VOOR": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.VENTRICULAR_AMPLITUDE_REGULATED,
                Parameters.VENTRICULAR_PULSE_WIDTH,
                Parameters.VENTRICULAR_SENSITIVITY,
                Parameters.REACTION_TIME,
                Parameters.RESPONSE_FACTOR,
                Parameters.RECOVERY_TIME,
            ],
            "VVIR": [
                Parameters.LOWER_RATE_LIMIT,
                Parameters.UPPER_RATE_LIMIT,
                Parameters.VENTRICULAR_AMPLITUDE_REGULATED,
                Parameters.VENTRICULAR_PULSE_WIDTH,
                Parameters.VENTRICULAR_SENSITIVITY,
                Parameters.VRP,
                Parameters.REACTION_TIME,
                Parameters.RESPONSE_FACTOR,
                Parameters.RECOVERY_TIME,
            ],
        }

        self.num_columns = 3
        self.num_rows = 4
        self.last_row = (
            4 * len(self.pacing_modes_map.get(pacing_mode, None)) // self.num_columns
        )
        self.closed = False
        self.database = Database()
        self.pending_after_id = None

    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        self.load_grid(True, False, True)
        parameters = self.pacing_modes_map.get(self.pacing_mode, None)

        self.screen.update()

        for i, param in enumerate(parameters):
            super().create_label(
                f"{param.value.name} ({param.value.unit})",
                self.config.font_size,
                wraplength=self.column_size - 5,
            ).grid(
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

        self.screen.bind("<Escape>", lambda event: self.close())
        self.screen.bind("<Return>", lambda event: self.ok())

        self.screen.mainloop()

    def apply(self, from_button: bool = True):
        param_map = self.pacing_modes_map[self.pacing_mode]
        param_data = {param.value.name: "" for param in param_map}

        for funky, param in zip(self.widgets["FunkyWidget"], param_data):
            param_data[param] = funky.get()
        
        for param in self.current_user.parameter_dict[self.pacing_mode]:
            if param in param_data.keys():
                continue
            param_data.update({param: self.current_user.parameter_dict[self.pacing_mode][param]}) 


        self.database.update_parameters(
            self.current_user, self.current_user.username, self.pacing_mode, param_data
        )
        if from_button:
            applied_msg = super().create_label(
                "Settings applied", 11, True, "calibri", fg="green"
            )
            applied_msg.grid(row=self.last_row + 2, column=1, pady=2)
            destroy_applied_msg = partial(applied_msg.destroy)
            try:
                self.pending_after_id = self.screen.after(2000, destroy_applied_msg)
            except tk.TclError:
                pass

    def ok(self):
        """Do both apply and close, similar features to Windows settings"""
        self.apply(from_button=False)
        self.closed = True
        # Check if any after events are still running
        if self.pending_after_id:
            self.screen.after_cancel(self.pending_after_id)
        self.prepare_screen_switch()

    def close(self):
        self.closed = True
        # Check if any after events are still running
        if self.pending_after_id:
            self.screen.after_cancel(self.pending_after_id)
        self.prepare_screen_switch()


class EgramScreen(Screen):
    def __init__(
        self,
        geometry: str,
        accessibility_config: AccessibilityConfig,
        bg_colour: str = "#8a8d91",
    ):
        """Initializes EgramScreen class with geometry and background colour."""
        super().__init__(geometry, accessibility_config, bg_colour)
        self.title = "DCM Application - Egram"
        self.closed = False

    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)

        # Create the figure
        fig, (ax1, ax2) = plt.subplots(2, 1, constrained_layout=True)

        # Placeholder x and y data (This is to be replaced with the data received from the board)
        x = np.linspace(0, 10, 1000)
        y = 4000 * (np.sin(x) ** 63 * np.sin(x + 1.5) * 8)

        # Plot the Atrium Signals
        ax1.plot(x, y)
        ax1.set_title("Atrium Signals")

        # Plot the Ventricle Signals
        ax2.plot(x, y)
        ax2.set_title("Ventricle Signals")

        # Set common axis labels
        fig.supxlabel("Time (ms)")
        fig.supylabel("Voltage (mV)")

        # Embed the plot in the Tkinter window
        canvas = FigureCanvasTkAgg(fig, master=self.screen)
        canvas.draw()
        canvas.get_tk_widget().pack(side="top", fill="none", pady=30)
        """
        super().create_logo("DCM_group9/imgs/heartLogo.png", (150, 150)).pack(
            side="bottom", pady=50
        )
        """
        super().create_button("Close", self.close).pack(side="top", padx=200, pady=20)
        self.screen.bind("<Escape>", lambda event: self.close())
        self.screen.mainloop()

    def close(self):
        plt.close()
        self.closed = True
        self.prepare_screen_switch()
