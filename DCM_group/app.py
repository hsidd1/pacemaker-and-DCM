import tkinter as tk 
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

root = tk.Tk()
root.title("DCM Group")
root.geometry("600x500")
# root.attributes('-fullscreen', True)

tk.Label(root, text="Register Username and Password", bg="blue").pack()
tk.Label(root, text="").pack()

# username labels
username_label = tk.Label(root, text="Username * ")
username_label.pack()

# username entry
username_entry = tk.Entry(root, text="username")
username_entry.pack()

# password labels
password_label = tk.Label(root, text="Password * ")
password_label.pack()

# password entry
password_entry = tk.Entry(root, text="password", show='*')
password_entry.pack()
tk.Label(root, text="").pack()

# function for register button
def register_user():
    username_info = username_entry.get()
    password_info = password_entry.get()

    # Error handling
    if not username_info or not password_info:
        # Empty string
        message = tk.Label(root, text="Please enter valid username and password", fg="red", font=("calibri", 11))
        message.pack()
        root.after(2000, lambda: message.destroy())
        return
    if username_info in Database.users_map.keys():
        # Username already exists
        message = tk.Label(root, text="Username already exists", fg="red", font=("calibri", 11))
        message.pack()
        root.after(2000, lambda: message.destroy())
        return
    if Database.get_user_count() >= 10:
        # Too many users
        message = tk.Label(root, text="Too many users", fg="red", font=("calibri", 11))
        message.pack()
        root.after(2000, lambda: message.destroy())
        return
    
    registered_user = User(username_info, password_info)
    Database.write_to_file(registered_user)

    username_entry.delete(0, tk.END)
    password_entry.delete(0, tk.END)

    message = tk.Label(root, text="Registration Success", fg="green", font=("calibri", 11))
    message.pack()
    root.after(2000, lambda: message.destroy())

tk.Button(root, text="Register", width=10, height=1, bg="blue", command = register_user).pack()

root.mainloop()