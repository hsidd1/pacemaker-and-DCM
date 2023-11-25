"""Main application class for the DCM application.

Handles the state of the application and the transitions between screens.
App is run here.
"""
from __future__ import annotations

from ui_config.config import AccessibilityConfig
from backend.backend import Backend
from threading import Thread
from multiprocessing import Process, shared_memory, Semaphore
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
        )
        egram_screen.run_screen()

        self.page_geometry = egram_screen.geometry
        if egram_screen.closed:
            self.current_screen = "HomepageScreen"
        else:
            self.current_screen = None
        self.current_screen_ref[0] = self.current_screen



serialobj = serial.Serial("COM8", 115200)

import struct
import time
from random import Random

def pacemaker_ecg_emulator(current_screen):
    st = struct.Struct('2i')
    while current_screen[0]:
        random_av = Random.randint(Random(), 0, 10)
        random_vv = Random.randint(Random(), 0, 10)
        packed_data = st.pack(*[random_av, random_vv])
        serialobj.write(packed_data)
        #print(packed_data)
        time.sleep(0.002)

if __name__ == "__main__":
    #shm = shared_memory.SharedMemory(name="dee", create=True, size=1024)
    app = Application()
    p1 = Thread(target=app.backend.open_port, args=(app.current_screen_ref,))
    p2 = Thread(target=app.backend.get_egram_data, args=(app.current_screen_ref,))
    p3 = Thread(target=pacemaker_ecg_emulator, args=(app.current_screen_ref,))
    #p2 = Process(target=app.run_app)
    #p1 = Process(target=app.backend.open_port)
    p1.start()
    p2.start()
    p3.start()

    app.run_app()