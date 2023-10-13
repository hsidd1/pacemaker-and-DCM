import tkinter as tk
from tkinter import ttk
from numpy import arange


class FunkyWidget(tk.Frame):
    def __init__(self, screen, limits: dict, default: float, **kwargs,):
        super().__init__(screen, **kwargs)

        self.limits = limits
        self.interval_list = list(self.limits.keys())
        self.increment_list = list(self.limits.values())

        self.intervals = [ f"{key[0]}-{key[1]}" if key[0] != key[1] else str(key[0]) for key in limits.keys()]

        self.var = tk.StringVar(self)
        self.var.set(default)  # Set the default value

        self.current_crement, self.current_interval = self.get_increment_interval(self.var.get())

        self.option_menu = ttk.Combobox(self, textvariable=self.var, values=self.intervals, width=10)
        self.option_menu.pack(side="left")

        self.decrement_button = tk.Button(self, text="-", command=self.decrement_value)
        self.decrement_button.pack(side="left")

        self.increment_button = tk.Button(self, text="+", command=self.increment_value)
        self.increment_button.pack(side="left")

        self.option_menu.bind('<<ComboboxSelected>>', self.update_display)
    

    def update_increment(self, selected_interval):
        self.current_interval = selected_interval
        self.increment = self.limits[selected_interval]

    def update_display(self, event):
        int_string = self.var.get()
        min_value = int_string.split('-')[0]
        self.var.set(min_value)

    def get_increment_interval(self, current_value: float):
        increment = 0
        if (current_value == "No Data"):
            return None, None
        for intervals in self.limits.keys():
            inc = self.limits[intervals]
            if (inc):
                interval = arange(float(intervals[0]), float(intervals[1]+inc), float(inc))
                if (float(current_value) in interval):
                    increment = inc
                    return increment, intervals
            else:
                if (current_value == intervals[0]):
                    increment = inc
                    return increment, intervals
                
    def get_next_increment_interval(self, current_interval: tuple):
        index = (self.interval_list.index(self.current_interval) + 1) % len(self.interval_list)
        return self.increment_list[index], self.interval_list[index]
    
    def get_previous_increment_interval(self, current_interval: tuple):
        index = (self.interval_list.index(self.current_interval) - 1) % len(self.interval_list)
        return self.increment_list[index], self.interval_list[index]

    def increment_value(self):
        epsilon = 1e-10
        if (self.var.get() == "No Data"):
            self.current_interval = self.interval_list[0]
            self.current_crement = self.increment_list[0]
            self.var.set(self.current_interval[0])
            return
        current_value = float(self.var.get())
        next_increment, next_interval = self.get_next_increment_interval(self.current_interval)
        # print("===================================")
        # print(f"currentval - {current_value}\ncurrentinc - {self.current_crement}\ncurrint - {self.current_interval}")
        # print("===================================")
        # print(f"nextval - {current_value+self.current_crement}\nnextinc - {next_increment}\nnextint - {next_interval}")
        # print("===================================")
        if (current_value+self.current_crement > self.current_interval[1] + epsilon):
            self.current_crement, self.current_interval = next_increment, next_interval
            current_value = self.current_interval[0]
        else:
            current_value += self.current_crement
            if (next_interval is not None and current_value == next_interval[0]):
                self.current_crement, self.current_interval = next_increment, next_interval
        self.var.set(str(round(current_value, 2)))

    def decrement_value(self):
        epsilon = 1e-10
        if (self.var.get() == "No Data"):
            self.current_interval = self.interval_list[-1]
            self.current_crement = self.increment_list[-1]
            self.var.set(self.current_interval[1])
            return
        current_value = float(self.var.get())
        next_increment, next_interval = self.get_next_increment_interval(self.current_interval)
        if (current_value-self.current_crement < self.current_interval[0] - epsilon):
            self.current_crement, self.current_interval = next_increment, next_interval
            current_value = self.current_interval[1]
        else:
            current_value -= self.current_crement
            if (next_interval is not None and current_value == next_interval[1]):
                self.current_crement, self.current_interval = next_increment, next_interval
        self.var.set(str(round(current_value, 2)))
        
    def get(self):
        return self.var.get()