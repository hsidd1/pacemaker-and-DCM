class ApplicationFSM:
    def __init__(self) -> None:

        self.current_state = "WelcomeScreen"
        self.states = {
            "WelcomeScreen" : self.handle_welcome_screen,
            "HomepageScreen" : self.handle_homepage_screen,
            "SettingsScreen" : self.handle_settings_screen
        }

    def run_app(self):
        pass
    
    def handle_welcome_screen(self):
        pass

    def handle_homepage_screen(self):
        pass
    
    def handle_settings_screen(self):
        pass