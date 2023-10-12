from screens import *

class ApplicationFSM:
    def __init__(self) -> None:

        self.page_geometry: str = "600x500"
        self.current_user = None
        self.current_state = "WelcomeScreen"
        self.states = {
            "WelcomeScreen" : self.handle_welcome_screen,
            "HomepageScreen" : self.handle_homepage_screen,
            "SettingsScreen" : self.handle_settings_screen
        }

    def run_app(self):
        while (self.current_state):
            state_handler = self.states[self.current_state]
            state_handler()
    
    def handle_welcome_screen(self):
        welcome_screen = WelcomeScreen(self.page_geometry)
        welcome_screen.run_screen()

        self.page_geometry = welcome_screen.geometry
        if (welcome_screen.logged_in):
            self.current_state = "HomepageScreen"
            self.current_user = welcome_screen.logged_user
        else:
            self.current_state = None

    def handle_homepage_screen(self):
        homepage_screen = HomepageScreen(self.page_geometry, self.current_user)
        homepage_screen.run_screen()

        if (homepage_screen.logged_out):
            self.current_state = "WelcomeScreen"
            self.current_user = None
        else:
            self.current_state = None
    
    def handle_settings_screen(self):
        pass