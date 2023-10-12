import tkinter as tk

class FunkyWidget(tk.Frame):
    def __init__(self, screen, limits: dict, default, **kwargs,):
        super().__init__(screen, **kwargs)

        self.limits = limits

        self.intervals = [str(key) if limits[key] else str(key[0]) for key in limits.keys()]

        self.var = tk.StringVar(self)
        self.var.set(default)  # Set the default value

        self.option_menu = tk.OptionMenu(self, self.var, *self.intervals)
        self.option_menu.pack(side="left")

        self.decrement_button = tk.Button(self, text="-", command=self.decrement_value)
        self.decrement_button.pack(side="left")

        self.increment_button = tk.Button(self, text="+", command=self.increment_value)
        self.increment_button.pack(side="left")
    

    def update_increment(self, selected_interval):
        self.current_interval = selected_interval
        self.increment = self.limits[selected_interval]


    def increment_value(self):
        pass

    def decrement_value(self):
        pass
    
    