"""Main application program for the DCM application.

This file contains all the screens of the application including
the welcome screen, homepage screen, settings screen and pacing
parameters display screen.
"""
from screens import *

class Application:
    def __init__(self) -> None:
        self.page_geometry: str = "800x600"
        self.current_user: User | None = None
        self.pacing_mode: str | None = None
        self.current_screen: str = "WelcomeScreen"
        self.screens: dict = {
            "WelcomeScreen": self.handle_welcome_screen,
            "HomepageScreen": self.handle_homepage_screen,
            "SettingsScreen": self.handle_settings_screen,
            "EgramScreen": self.handle_egram_screen,
        }

    def run_app(self):
        while self.current_screen:
            state_handler = self.screens[self.current_screen]
            state_handler()

    def handle_welcome_screen(self):
        welcome_screen = WelcomeScreen(self.page_geometry)
        welcome_screen.run_screen()

        self.page_geometry = welcome_screen.geometry
        if welcome_screen.logged_in:
            self.current_screen = "HomepageScreen"
            self.current_user = welcome_screen.logged_user
        else:
            self.current_screen = None

    def handle_homepage_screen(self):
        homepage_screen = HomepageScreen(self.page_geometry, self.current_user)
        homepage_screen.run_screen()

        self.page_geometry = homepage_screen.geometry
        if homepage_screen.logged_out:
            self.current_screen = "WelcomeScreen"
            self.current_user = None
        elif homepage_screen.settings_view:
            self.current_screen = "SettingsScreen"
            self.pacing_mode = homepage_screen.pacing_mode
        elif (homepage_screen.egram_view):
            self.current_screen = "EgramScreen"
            self.pacing_mode = homepage_screen.pacing_mode
        else:
            self.current_screen = None

    def handle_settings_screen(self):
        settings_screen = SettingsScreen(
            self.page_geometry, self.current_user, self.pacing_mode
        )
        settings_screen.run_screen()

        self.page_geometry = settings_screen.geometry
        if settings_screen.closed:
            self.current_screen = "HomepageScreen"
        else:
            self.current_screen = None

    def handle_egram_screen(self):
        egram_screen = EgramScreen(self.page_geometry)
        egram_screen.run_screen()

        self.page_geometry = egram_screen.geometry
        if egram_screen.closed:
            self.current_screen = "HomepageScreen"
        else:
            self.current_screen = None

if __name__ == "__main__":
    app = Application()
    app.run_app()
