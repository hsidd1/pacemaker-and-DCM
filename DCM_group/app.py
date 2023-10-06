import tkinter as tk 
from PIL import ImageTk, Image
from user import User
from database import Database

Database = Database()

def welcome_screen():
    """Welcome page for login and registration of users"""
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

    def register_user():
        """Registers user and writes to file if valid"""

        username_info = username_entry.get()
        password_info = password_entry.get()
        if not username_info or not password_info:
            # Empty entry
            message = tk.Label(welcome_page, text="Please enter valid username and password", fg="red", background="#8a8d91", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if Database.get_user_count() >= 10:
            # Too many users
            message = tk.Label(welcome_page, text="Too many users", fg="red", background="#8a8d91", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info in Database.users_map.keys():
            # Username already exists
            message = tk.Label(welcome_page, text="Username already exists", fg="red", background="#8a8d91", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        
        # create registered user object
        registered_user = User(username_info, password_info)
        Database.write_to_file(registered_user)

        username_entry.delete(0, tk.END)
        password_entry.delete(0, tk.END)

        message = tk.Label(welcome_page, text="Registration Success", fg="green", background="#8a8d91", font=("calibri", 11))
        message.pack()
        welcome_page.after(2000, lambda: message.destroy())

    def login_user():
        """Logs user into homepage if user exists and if password is correct"""
        username_info = username_entry.get()
        password_info = password_entry.get()

        if not username_info or not password_info:
            # Empty string
            message = tk.Label(welcome_page, text="Please enter valid username and password", fg="red", background="#8a8d91", font=("calibri", 11, "bold"))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if username_info not in Database.users_map.keys():
            # Username does not exist
            message = tk.Label(welcome_page, text="User does not exist", fg="red", background="#8a8d91", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        if Database.users_map[username_info] != password_info:
            # Incorrect password
            message = tk.Label(welcome_page, text="Incorrect password", fg="red", background="#8a8d91", font=("calibri", 11))
            message.pack()
            welcome_page.after(2000, lambda: message.destroy())
            return
        
        # Login success
        message = tk.Label(welcome_page, text="Login Success", fg="green", background="#8a8d91", font=("calibri", 11))
        message.pack()
        # open home page 
        homepage_screen()
        welcome_page.destroy()

    # Log in and register buttons
    login_btn    = tk.Button(welcome_page, text="Login", width=10, height=1, bg="#eda758", command = login_user)
    login_btn.pack(pady=10)
    register_btn = tk.Button(welcome_page, text="Register", width=10, height=1, bg="#eda758", command = register_user)
    register_btn.pack()

    # Image logo
    logo = Image.open("DCM_group/imgs/heartLogo.png")
    logo_resized = logo.resize((100, 100)) # maximum size to be able to still display three error messages on screen
    logo_resized = ImageTk.PhotoImage(logo_resized)
    logo_label = tk.Label(welcome_page, image = logo_resized, background="#8a8d91")
    logo_label.pack(side="bottom", pady=50)

    welcome_page.mainloop()

def homepage_screen():
    """Homepage screen for choosing pacing mode and viewing pacing data
       Takes User to pacing_display_screen() when all parameters are filled in"""
    # configuring the page attributes
    homepage_screen = tk.Tk()
    homepage_screen.title("DCM Application - Home Page")
    homepage_screen.geometry("600x500")
    homepage_screen.configure(bg="#8a8d91")
    hompage_title_label = tk.Label(homepage_screen, text="Pacemaker Device Controller-Monitor", font=("Helvetica", 25, "bold"), background="#8a8d91")
    hompage_title_label.pack(pady=10)

    # --------------- page features ------------------ #
    # dropdown menu to choose pacing mode
    pacing_mode_label = tk.Label(homepage_screen, text="Choose pacing mode:", background="#8a8d91", font=("Helvetica", 12))
    pacing_mode_label.pack(pady=4)
    pacing_mode = tk.StringVar(homepage_screen)
    pacing_mode.set("") # default value
    pacing_mode_dropdown = tk.OptionMenu(homepage_screen, pacing_mode, "AOO", "AAI", "VOO", "VVI")
    pacing_mode_dropdown.pack(pady=1)
    # get input into a variable (test this)
    pacing_mode_input = pacing_mode.get()
    
    # ----------------- after choosing programmable parameters --------------------- #
    # if everything is filled in and the user wants to see the data filled in:
    #     pacing_display_screen()
    #     homepage_screen.destroy()
    
def pacing_display_screen():
    pass

def main():
    welcome_screen()
    # homepage_screen() # for testing, skip login

if __name__ == "__main__":
    main()
    tk._exit()
