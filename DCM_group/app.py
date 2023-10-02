import tkinter as tk 
import os 

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
        return self.user_string()

class Database:
    def __init__(self, database: str = DATABASE):
        self.database = database
        self.users_map = {}

    def get_user_count(self):
        return len(self.users_map)

    def add_user(self, user: User):
        self.users_map[user.username] = user.password

    def remove_user(self, username: str):
        del self.users_map[username]

    def write_to_file(self, user: User):
        self.add_user(user)
        if user in self.users_map:
            user.exists = True
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

def register_user():
    username_info = username_entry.get()
    password_info = password_entry.get()

    # Error handling
    if username_info == "" or password_info == "":
        # Empty string
        tk.Label(root, text="Please enter valid username and password", fg="red", font=("calibri", 11)).pack()
        return
    if username_info in Database.users_map.keys():
        # Username already exists
        tk.Label(root, text="Username already exists", fg="red", font=("calibri", 11)).pack()
        return
    
    registered_user = User(username_info, password_info)
    Database.write_to_file(registered_user)

    username_entry.delete(0, tk.END)
    password_entry.delete(0, tk.END)

    tk.Label(root, text="Registration Success", fg="green", font=("calibri", 11)).pack()
tk.Button(root, text="Register", width=10, height=1, bg="blue", command = register_user).pack()

root.mainloop()