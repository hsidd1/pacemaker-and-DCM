"""Main application class for the DCM application.

Handles the state of the application and the transitions between screens.
App is run here.
"""
from __future__ import annotations

from ui_config.config import AccessibilityConfig
from backend.backend import Backend
from threading import Thread
from screens import *


class Application:
    def __init__(self) -> None:
        """Initializes Application class with page geometry, current user and pacing mode parameters."""
        self.accessibility_config = AccessibilityConfig()
        self.backend = Backend()
        self.page_geometry: str = "800x600"
        self.current_user: User | None = None
        self.pacing_mode: str | None = None
        self.current_screen: str = "WelcomeScreen"
        self.current_screen_ref = ["WelcomeScreen"]
        self.screens: dict = {
            "WelcomeScreen": self.handle_welcome_screen,
            "AccessibilitySettingsScreen": self.handle_accessibility_settings_screen,
            "HomepageScreen": self.handle_homepage_screen,
            "SettingsScreen": self.handle_settings_screen,
            "EgramScreen": self.handle_egram_screen,
        }

    def run_app(self):
        """Runs the application."""
        while self.current_screen:
            state_handler = self.screens[self.current_screen]
            state_handler()

    def handle_welcome_screen(self):
        """Handles the WelcomeScreen state of the application."""
        welcome_screen = WelcomeScreen(self.page_geometry, self.accessibility_config)
        welcome_screen.run_screen()

        self.page_geometry = welcome_screen.geometry
        if welcome_screen.logged_in:
            self.current_screen = "HomepageScreen"
            self.current_user = welcome_screen.logged_user
        elif welcome_screen.view_settings:
            self.current_screen = "AccessibilitySettingsScreen"
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen

    def handle_accessibility_settings_screen(self):
        accessibility_settings_screen = AccessibilitySettingsScreen(
            self.page_geometry, self.accessibility_config,
        )
        accessibility_settings_screen.run_screen()

        self.page_geometry = accessibility_settings_screen.geometry
        if accessibility_settings_screen.closed:
            self.current_screen = "WelcomeScreen"
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen

    def handle_homepage_screen(self):
        """Handles the HomepageScreen state of the application."""
        homepage_screen = HomepageScreen(
            self.page_geometry, self.accessibility_config, self.current_user, self.backend
        )
        homepage_screen.run_screen()

        self.page_geometry = homepage_screen.geometry
        if homepage_screen.logged_out:
            self.current_screen = "WelcomeScreen"
            self.current_user = None
        elif homepage_screen.settings_view:
            self.current_screen = "SettingsScreen"
            self.pacing_mode = homepage_screen.pacing_mode
        elif homepage_screen.egram_view:
            self.current_screen = "EgramScreen"
            self.pacing_mode = homepage_screen.pacing_mode
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen

    def handle_settings_screen(self):
        """Handles the SettingsScreen state of the application."""
        settings_screen = SettingsScreen(
            self.page_geometry,
            self.accessibility_config,
            self.current_user,
            self.pacing_mode,
        )
        settings_screen.run_screen()

        self.page_geometry = settings_screen.geometry
        if settings_screen.closed:
            self.current_screen = "HomepageScreen"
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen

    def handle_egram_screen(self):
        """Handles the EgramScreen state of the application."""
        egram_screen = EgramScreen(
            self.page_geometry,
            self.accessibility_config,
            self.backend
        )
        egram_screen.run_screen()

        self.page_geometry = egram_screen.geometry
        if egram_screen.closed:
            self.current_screen = "HomepageScreen"
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen

# from serial import Serial
# import random
# import struct

# ser = Serial("COM13", 115200)

# def chunk_data(data, chunk_size):
#     """Yield successive n-sized chunks from data."""
#     for i in range(0, len(data), chunk_size):
#         yield data[i:i + chunk_size]

# def pacemaker_ecg_emulator():
#     # int1 = random.randrange(0,100)
#     # int2 = random.randrange(0,100)
#     # buf = [int1, int2]
#     # packed_data = struct.pack('2i', *buf)
#     # ser.write(packed_data)

#     while True:
#         data = ser.read(64)
#         print(f"{data}\n")
#         for chunk in chunk_data(data, 8):
#             ser.write(chunk)
#         ser.flush()
        


if __name__ == "__main__":
    app = Application()
    p1 = Thread(target=app.backend.open_port, args=(app.current_screen_ref,))
    p2 = Thread(target=app.backend.get_egram_data, args=(app.current_screen_ref,))
    # p3 = Thread(target=pacemaker_ecg_emulator)
    p1.start()
    p2.start()
    # p3.start()

    app.run_app()