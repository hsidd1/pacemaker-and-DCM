import tkinter as tk 
from PIL import ImageTk, Image
# import os 

DATABASE = "DCM_group/database.txt"

class User:
    def __init__(self, username: str, password: str):
        self.username = username
        self.password = password

    def user_string(self) -> str:
        """for file writing"""
        return f"{self.username}\t{self.password}"
    
    def __str__(self) -> str:
        """for printing"""
        return f"User with username: {self.username} and password: {self.password}"

class Database:
    def __init__(self, database: str = DATABASE):
        self.database = database
        # map of users' usernames and passwords
        # read from file to see who exists and add them to map each run
        with open(self.database, "r") as f:
            self.users_map = {line.split()[0]: line.split()[1] for line in f.readlines() if line}

    def get_user_count(self) -> int:
        return len(self.users_map)

    def add_user(self, user: User):
        self.users_map[user.username] = user.password

    def remove_user(self, username: str):
        del self.users_map[username]

    def write_to_file(self, user: User):
        self.add_user(user)
        if user in self.users_map:
            user.exists = True # unused for now
        else:
            with open(self.database, "a") as f:
                f.write(f"{user.user_string()}\n")

Database = Database()

def welcome_screen():
    welcome_page = tk.Tk()
    welcome_page.title("DCM Application - Welcome Page")
    welcome_page.geometry("600x500")
    welcome_page.configure(bg="#8a8d91")# 3 a nice grey colour
    # welcome_page.attributes('-fullscreen', True)

    tk.Label(welcome_page, text="Pacemaker Device Controller-Monitor", font=("Helvetica", 25, "bold"), background="#8a8d91").pack(pady=10)

    # username labels
    username_label = tk.Label(welcome_page, text="Username:", background="#8a8d91", font=("Helvetica", 12))
    username_label.pack(pady=4)

    # username entry
    username_entry = tk.Entry(welcome_page, text="username")
    username_entry.pack(pady=1)

    # password labels
    password_label = tk.Label(welcome_page, text="Password:", background="#8a8d91", font=("Helvetica", 12))
    password_label.pack()

    # password entry
    password_entry = tk.Entry(welcome_page, text="password", show='*')
    password_entry.pack()

    # function for register button
    def register_user():
        username_info = username_entry.get()
        password_info = password_entry.get()

        # Error handling
        if not username_info or not password_info:
            # Empty string
            message = tk.Label(welcome_page, text="Please enter valid username and password", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info in Database.users_map.keys():
            # Username already exists
            message = tk.Label(welcome_page, text="Username already exists", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if Database.get_user_count() >= 10:
            # Too many users
            message = tk.Label(welcome_page, text="Too many users", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        
        registered_user = User(username_info, password_info)
        Database.write_to_file(registered_user)

        username_entry.delete(0, tk.END)
        password_entry.delete(0, tk.END)

        message = tk.Label(welcome_page, text="Registration Success", fg="green", font=("calibri", 11))
        message.pack()
        welcome_page.after(2000, lambda: message.destroy())

    def login_user():
        username_info = username_entry.get()
        password_info = password_entry.get()

        if not username_info or not password_info:
            # Empty string
            message = tk.Label(welcome_page, text="Please enter valid username and password", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info not in Database.users_map.keys():
            # Username does not exist
            message = tk.Label(welcome_page, text="User does not exist", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if Database.users_map[username_info] != password_info:
            # Incorrect password
            message = tk.Label(welcome_page, text="Incorrect password", fg="red", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        
        # Login success
        message = tk.Label(welcome_page, text="Login Success", fg="green", font=("calibri", 11))
        message.pack()
        # open home page 
        homepage_screen()
        welcome_page.destroy()
    # Buttons
    login_btn    = tk.Button(welcome_page, text="Login", width=10, height=1, bg="#eda758", command = login_user).pack(pady=10)
    register_btn = tk.Button(welcome_page, text="Register", width=10, height=1, bg="#eda758", command = register_user).pack()
    # Image logo
    logo = Image.open("DCM_group/imgs/heartLogo.png")
    logo_resized = logo.resize((200, 200))
    logo_resized = ImageTk.PhotoImage(logo_resized)
    logo_label = tk.Label(welcome_page, image = logo_resized, background="#8a8d91")
    logo_label.pack(side="bottom", pady=50)

    welcome_page.mainloop()

def homepage_screen():
    homepage_screen = tk.Tk()
    homepage_screen.title("DCM Application - Home Page")
    homepage_screen.geometry("600x500")
    # homepage_screen.configure(bg="#8a8d91") 3 a nice grey colour

if __name__ == "__main__":
    # start the application
    welcome_screen()