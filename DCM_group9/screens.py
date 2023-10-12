import tkinter as tk
from database import Database
from user import User

class Screen:

    def __init__(self, geometry: str, bg_colour: str = "#8a8d91"):
        self.bg_colour = bg_colour
        self.geometry = geometry
        self.screen: tk.Tk = None
        self.widgets = {
            "Button"     : [],
            "Entry"      : [],
            "Label"      : [],
            "OptionMenu" : []
        }
        self.page_width = 0
        self.page_height = 0
        self.num_columns = 11
        self.num_rows = 11


    def create_button(self, text: str, command: callable, width: int = 10, height: int = 1, bg_colour: str = "#eda758"):
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
        if(encrypted):
            entry = tk.Entry(self.screen,show="*")
        else:
            entry = tk.Entry(self.screen)
        self.widgets["Entry"].append(entry)
        return entry
    
    def create_label(self, text: str, fontsize: int, bold: bool = False, font: str = "Helvetica"):
        if(bold):
            input_font = (font, fontsize, "bold")
        else:
            input_font = (font, fontsize)
        label = tk.Label(
            self.screen,
            text=text,
            font=input_font,
            background="#8a8d91",
        )
        self.widgets["Label"].append(label)
        return label
    
    def bring_to_front(self):
        """Brings screen to front"""
        self.screen.lift()
        self.screen.attributes('-topmost',True)
        self.screen.after_idle(self.screen.attributes,'-topmost',False)
        self.screen.focus_force()   

    def load_grid(self):
        for i in range(0,self.num_columns):
            self.screen.columnconfigure(i, weight=1)
        for i in range(0,self.num_rows):
            self.screen.rowconfigure(i, weight=1)
        
    def run_screen(self):
        self.screen = tk.Tk()
        self.screen.geometry(self.geometry)
        self.screen.configure(bg=self.bg_colour)
        self.screen.update()
        self.page_height = self.screen.winfo_height()
        self.page_width = self.screen.winfo_width()
        self.rows, self.columns = self.screen.grid_size()
        self.bring_to_front()

    def close_screen(self):
        self.screen.destroy()


class WelcomeScreen(Screen):

    def __init__(self, geometry: str, bg_colour: str = "#8a8d91"):
        """Only the WelcomeScreen should have access to database !!!
        USE THE CURRENTUSER IN DEEPER SCREENS!!!!!!"""
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Welcome Page"
        self.database = Database()
        self.login = False
        self.logged_user = None
    
    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        super().create_label("Pacemaker Device Controller-Monitor", 25, True).pack(pady=10)
        super().create_label("Username", 12).pack(pady=4)
        super().create_entry().pack()
        super().create_label("Password", 12).pack()
        super().create_entry(True).pack()
        super().create_button("Login", self.login_user).pack(pady=10)
        super().create_button("Register", self.login_user).pack()
        self.screen.bind('<Return>', lambda event: self.login_user())
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
        

        self.login = True
        self.geometry = self.screen.geometry()
        self.close_screen()

class HomepageScreen(Screen):

    def __init__(self, geometry: str, current_user: User, bg_colour: str = "#8a8d91"):
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Home Page"
        self.current_user = current_user
        print(current_user.username, current_user.password, current_user.parameter_dict)
    
    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        self.screen.mainloop()

class SettingsScreen(Screen):

    def __init__(self, geometry: str, current_user: User, bg_colour: str = "#8a8d91"):
        super().__init__(geometry, bg_colour)
        self.title = "DCM Application - Pacing Mode Settings"
        self.current_user = current_user
        self.pacing_modes_map = {}
    
    def run_screen(self):
        super().run_screen()
        self.screen.title(self.title)
        self.screen.mainloop()