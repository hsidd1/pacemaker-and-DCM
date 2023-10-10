from user import User
import json
import tkinter as tk

DATABASE = "DCM_group9/database.json"


class Database:
    """Database class to store Users"""

    def __init__(self, database: str = DATABASE):
        self.database = database
        # map of users' usernames and passwords
        # read from file to see who exists and add them to map each run
        self.users_map = self.load_users_from_json()

    def load_users_from_json(self) -> dict:
        users_map = {}
        try:
            with open(self.database, "r") as f:
                try:
                    data = json.load(f)
                except json.JSONDecodeError:
                    data = []
                for user_dict in data:
                    try:
                        username = user_dict.get("username")
                        password = user_dict.get("password")
                        if username and password:
                            users_map[username] = password
                    except json.JSONDecodeError as e:
                        print(f"Error decoding JSON: {e}")
                    except KeyError as e:
                        print(f"KeyError: {e} - Invalid JSON structure")
        except FileNotFoundError:
            print(f"File not found: {self.database}")

        return users_map

    @property
    def get_user_count(self) -> int:
        """returns number of users in database"""
        return len(self.users_map)

    def __add_user(self, user: User):
        """Private method - adds user to database"""
        self.users_map[user.username] = user.password

    def __remove_user(self, username: str):
        """Private method - removes user from database"""
        del self.users_map[username]

    def write_to_file(self, user: User):
        """writes user to database when registered"""
        self.__add_user(user)
        with open(self.database, "r") as f:
            try:
                users = json.load(f)
            except json.JSONDecodeError:
                users = []
        users.append(user.to_dict())
        with open(self.database, "w") as f:
            # write the entire list of users to the file
            json.dump(users, f)

    def register_user(self, welcome_page: tk.Tk, username_entry: str, password_entry: str):
        """Registers user and writes to file if valid"""
        username_info = username_entry.get()
        password_info = password_entry.get()
        if not username_info or not password_info:
            # Empty entry
            message = tk.Label(welcome_page, text="Please enter valid username and password",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if self.get_user_count >= 10:
            # Too many users
            message = tk.Label(welcome_page, text="Too many users", fg="red",
                               background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info in self.users_map.keys():
            # Username already exists
            message = tk.Label(welcome_page, text="Username already exists",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info == password_info:
            # Username and password cannot be the same
            message = tk.Label(welcome_page, text="Username and password cannot be the same",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if password_info and len(username_info) < 3:
            # Username must be at least 3 characters
            message = tk.Label(welcome_page, text="Username must be at least 3 characters",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info and len(password_info) < 8:
            # Password must be at least 8 characters
            message = tk.Label(welcome_page, text="Password must be at least 8 characters",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if password_info and len(username_info) > 20:
            # Username must be at most 20 characters
            message = tk.Label(welcome_page, text="Username must be at most 20 characters",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info and len(password_info) > 64:
            # Password must be at most 64 characters
            message = tk.Label(welcome_page, text="Password must be at most 64 characters",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if password_info and username_info.isdigit():
            # Username cannot be all numbers
            message = tk.Label(welcome_page, text="Username cannot be all numbers",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info and password_info.isdigit():
            # Password cannot be all numbers
            message = tk.Label(welcome_page, text="Password cannot be all numbers",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return

        # remove spaces and make it case insensitive
        username_info = username_info.strip().lower()

        # create registered user object
        registered_user = User(username_info, password_info)
        self.write_to_file(registered_user)

        username_entry.delete(0, tk.END)
        password_entry.delete(0, tk.END)

        message = tk.Label(welcome_page, text="Registration Success",
                           fg="green", background="#8a8d91", font=("calibri", 11))
        message.pack()
        welcome_page.after(2000, lambda: message.destroy())
        return

    def login_user(self, welcome_page: tk.Tk, username_entry: str, password_entry: str, homepage_screen: tk.Tk):
        """Logs user into homepage if user exists and if password is correct"""
        username_info = username_entry.get()
        password_info = password_entry.get()

        if not username_info or not password_info:
            # Empty string
            message = tk.Label(welcome_page, text="Please enter valid username and password",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info not in self.users_map.keys():
            # Username does not exist
            message = tk.Label(welcome_page, text="User does not exist",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if self.users_map[username_info] != password_info:
            # Incorrect password
            message = tk.Label(welcome_page, text="Incorrect password",
                               fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return

        # Login success
        message = tk.Label(welcome_page, text="Login Success",
                           fg="green", background="#8a8d91", font=("calibri", 11))
        message.pack()
        # open home page
        homepage_screen()
        welcome_page.destroy()
