import tkinter as tk 
from PIL import ImageTk, Image
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
        """wrapper for Database.register_user()"""
        Database.register_user(welcome_page=welcome_page, username_entry=username_entry, password_entry=password_entry)
    
    def login_user():
        """wrapper for Database.login_user()
           takes user to homepage_screen() if successful"""
        Database.login_user(welcome_page=welcome_page, username_entry=username_entry, password_entry=password_entry, homepage_screen=homepage_screen)
    
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
    hompage_title_label.grid(row=0, column=0, columnspan=10, pady=10)

    # --------------- page features ------------------ #
    # dropdown menu to choose pacing mode
    pacing_mode_label = tk.Label(homepage_screen, text="Choose pacing mode:", background="#8a8d91", font=("Helvetica", 11))
    pacing_mode_label.grid(row=1, column=0, columnspan=2, pady=2)
    pacing_mode = tk.StringVar(homepage_screen)
    pacing_mode.set("") # default value
    pacing_mode_dropdown = tk.OptionMenu(homepage_screen, pacing_mode, "AOO", "AAI", "VOO", "VVI")
    pacing_mode_dropdown.grid(row=1, column=2, pady=2)
    # get input into a variable (test this)
    pacing_mode_input = pacing_mode.get()
    
     # Other Variables
    LowerRate_label = tk.Label(homepage_screen, text="Lower Rate Limit:", background="#8a8d91", font=("Helvetica", 11))
    LowerRate_label.grid(row=2, column=0, columnspan=2, pady=2)
    LowerRate_entry = tk.Entry(homepage_screen)
    LowerRate_entry.grid(row=2, column=2, pady=2)

    UpperRate_label = tk.Label(homepage_screen, text="Upper Rate Limit:", background="#8a8d91", font=("Helvetica", 11))
    UpperRate_label.grid(row=3, column=0, columnspan=2, pady=2)
    UpperRate_entry = tk.Entry(homepage_screen)
    UpperRate_entry.grid(row=3, column=2, pady=2)

    AtrialAmp_label = tk.Label(homepage_screen, text="Atrial Amplitude:", background="#8a8d91", font=("Helvetica", 11))
    AtrialAmp_label.grid(row=4, column=0, columnspan=2, pady=2)
    AtrialAmp_entry = tk.Entry(homepage_screen)
    AtrialAmp_entry.grid(row=4, column=2, pady=2)

    AtrialPulseWidth_label = tk.Label(homepage_screen, text="Atrial Pulse Width:", background="#8a8d91", font=("Helvetica", 11))
    AtrialPulseWidth_label.grid(row=5, column=0, columnspan=2, pady=2)
    AtrialPulseWidth_entry = tk.Entry(homepage_screen)
    AtrialPulseWidth_entry.grid(row=5, column=2, pady=2)

    VentricularAmp_label = tk.Label(homepage_screen, text="Ventricular Amplitude:", background="#8a8d91", font=("Helvetica", 11))
    VentricularAmp_label.grid(row=6, column=0, columnspan=2, pady=2)
    VentricularAmp_entry = tk.Entry(homepage_screen)
    VentricularAmp_entry.grid(row=6, column=2, pady=2)

    VentricularPulseWidth_label = tk.Label(homepage_screen, text="Ventricular Pulse Width:", background="#8a8d91", font=("Helvetica", 11))
    VentricularPulseWidth_label.grid(row=7, column=0, columnspan=2, pady=2)
    VentricularPulseWidth_entry = tk.Entry(homepage_screen)
    VentricularPulseWidth_entry.grid(row=7, column=2, pady=2)

    Vrp_label = tk.Label(homepage_screen, text="VRP:", background="#8a8d91", font=("Helvetica", 11))
    Vrp_label.grid(row=8, column=0, columnspan=2, pady=2)
    Vrp_entry = tk.Entry(homepage_screen)
    Vrp_entry.grid(row=8, column=2, pady=2)

    Arp_label = tk.Label(homepage_screen, text="ARP:", background="#8a8d91", font=("Helvetica", 11))
    Arp_label.grid(row=9, column=0, columnspan=2, pady=2)
    Arp_entry = tk.Entry(homepage_screen)
    Arp_entry.grid(row=9, column=2, pady=2)

    # Button to go back to welcome page at bottom left
    def logout():
        """Logs user out and takes them back to welcome page
           destroys homepage_screen"""
        homepage_screen.destroy()
        welcome_screen()
    back_btn = tk.Button(homepage_screen, text="Logout", width=10, height=1, bg="#eda758", command=logout)
    back_btn.grid(row=10, column=0, pady=10)

    
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
