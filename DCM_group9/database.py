"""Contains Database class which stores users' usernames, passwords and pacing mode parameters."""

from user import User
import json
import tkinter as tk

DATABASE = "DCM_group9/database.json"


class Database:
    def __init__(self, database: str = DATABASE, users_map: dict | None = None):
        """Initializes Database class with database file path.
        :param database: path to database file
        :param users_map: dictionary of users
        """
        self.database = database
        self.users_map = self.__load_users_from_json()

    def __load_users_from_json(self) -> dict:
        """Loads users from json file and returns a dictionary of users and
        passwords for users_map field"""
        users_map = {}
        try:
            with open(self.database, "r") as f:
                try:
                    data = json.load(f)
                except json.JSONDecodeError:
                    data = []
                try:
                    for key in data[0]:
                        try:
                            username = key
                            password = data[0][key]["password"]
                            if username and password:
                                users_map[username] = password
                        except json.JSONDecodeError as e:
                            print(f"Error decoding JSON: {e}")
                        except KeyError as e:
                            print(f"KeyError: {e} - Invalid JSON structure")
                except IndexError:
                    users_map = {}
        except FileNotFoundError:
            print(f"File not found: {self.database}")

        return users_map

    @property
    def get_user_count(self) -> int:
        """returns number of users in database"""
        return len(self.users_map)

    def __add_user(self, user: User):
        """Private method - adds user to database
        :param user: User object"""
        self.users_map[user.username] = user.password

    def __remove_user(self, username: str):
        """Private method - removes user from database
        :param username: username of user to be removed"""
        del self.users_map[username]

    def __write_to_file(self, user: User):
        """writes user to database when registered
        :param user: User object"""
        self.__add_user(user)
        with open(self.database, "r") as f:
            try:
                users = json.load(f)
            except json.JSONDecodeError:
                users = []
            if not users:
                users.append(user.to_dict())
            else:
                users[0].update(user.to_dict())
        with open(self.database, "w") as f:
            # Write the entire list of users to the file
            json.dump(users, f, indent=4)

    def register_user(
        self, welcome_page: tk.Tk, username_entry, password_entry
    ) -> bool:
        """Registers user and writes to file if valid
        :param welcome_page: welcome page window from main app
        :param username_entry: username entry from welcome screen
        :param password_entry: password entry from welcome screen
        :return: True if registration successful, False otherwise"""
        username_info = username_entry.get()
        password_info = password_entry.get()

        # Check if username and password are valid
        if not username_info or not password_info:
            # Empty entry
            message = tk.Label(
                welcome_page,
                text="Please enter valid username and password",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if self.get_user_count >= 10:
            # Too many users
            message = tk.Label(
                welcome_page,
                text="Too many users",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info.lower() in map(str.lower, self.users_map.keys()):
            # Username already exists
            message = tk.Label(
                welcome_page,
                text="Username already exists",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info == password_info:
            # Username and password cannot be the same
            message = tk.Label(
                welcome_page,
                text="Username and password cannot be the same",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if password_info and len(username_info) < 3:
            # Username must be at least 3 characters
            message = tk.Label(
                welcome_page,
                text="Username must be at least 3 characters",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info and len(password_info) < 8:
            # Password must be at least 8 characters
            message = tk.Label(
                welcome_page,
                text="Password must be at least 8 characters",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if password_info and len(username_info) > 20:
            # Username must be at most 20 characters
            message = tk.Label(
                welcome_page,
                text="Username must be at most 20 characters",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info and len(password_info) > 64:
            # Password must be at most 64 characters
            message = tk.Label(
                welcome_page,
                text="Password must be at most 64 characters",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if password_info and username_info.isdigit():
            # Username cannot be all numbers
            message = tk.Label(
                welcome_page,
                text="Username cannot be all numbers",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info and password_info.isdigit():
            # Password cannot be all numbers
            message = tk.Label(
                welcome_page,
                text="Password cannot be all numbers",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if not username_info.isalnum():
            message = tk.Label(
                welcome_page,
                text="Username cannot contain special characters",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False

        # Remove spaces and make user info case insensitive
        username_info = username_info.strip().lower()

        # Create registered user object
        registered_user = User(username_info, password_info)
        self.__write_to_file(registered_user)

        username_entry.delete(0, tk.END)
        password_entry.delete(0, tk.END)

        message = tk.Label(
            welcome_page,
            text="Registration Success",
            fg="green",
            background="#8a8d91",
            font=("calibri", 11),
        )
        message.pack()
        welcome_page.after(2000, lambda: message.destroy())
        return True

    def login_user(
        self,
        welcome_page: tk.Tk,
        username_entry,
        password_entry,
    ) -> bool:
        """Logs user into homepage if user exists and if password is correct
        :param welcome_page: welcome page window from main app
        :param username_entry: username entry from welcome screen
        :param password_entry: password entry from welcome screen
        :param homepage_screen: home page window from main app to be opened
        :return: True if login successful, False otherwise"""
        username_info = username_entry.get().lower()
        password_info = password_entry.get()

        # Check if username and password are valid
        if not username_info or not password_info:
            # Empty string
            message = tk.Label(
                welcome_page,
                text="Please enter valid username and password",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if username_info.lower() not in map(str.lower, self.users_map.keys()):
            # Username does not exist
            message = tk.Label(
                welcome_page,
                text="User does not exist",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False
        if self.users_map[username_info] != password_info:
            # Incorrect password
            message = tk.Label(
                welcome_page,
                text="Incorrect password",
                fg="red",
                background="#8a8d91",
                font=("calibri", 11, "bold"),
            )
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return False

        # Login success
        message = tk.Label(
            welcome_page,
            text="Login Success",
            fg="green",
            background="#8a8d91",
            font=("calibri", 11),
        )
        message.pack()

        # Open home page
        return True

    def update_parameters(
        self, user: User, current_user: str, pacing_mode: str, data: dict
    ) -> None:
        """Updates pacing mode parameters of the user and writes to json database.
        :param user: User object
        :param current_user: username of the user
        :param pacing_mode: pacing mode of the user
        :param data: pacing mode parameters of the user
        """
        with open(self.database, "r") as f:
            try:
                users = json.load(f)
            except json.JSONDecodeError:
                users = []
            users[0][current_user]["pacing_mode_params"][pacing_mode] = data
        with open(self.database, "w") as f:
            # Write the entire list of users to the file
            json.dump(users, f, indent=4)
        user.update_parameters(data, pacing_mode)

    def read_from_file(self) -> list:
        """Reads users from database file and returns a list of users
        :return: list of users"""
        with open(self.database, "r") as f:
            try:
                users = json.load(f)
            except json.JSONDecodeError:
                users = []
        return users
