"""Contains custom widgets for the GUI."""
import tkinter as tk
from tkinter import ttk
from numpy import arange


class FunkyWidget(tk.Frame):
    def __init__(
        self,
        screen,
        limits: dict,
        default: float,
        **kwargs,
    ):
        super().__init__(screen, **kwargs)

        self.limits = limits
        self.interval_list = list(self.limits.keys())
        self.increment_list = list(self.limits.values())

        self.intervals = [
            f"{key[0]}-{key[1]}" if key[0] != key[1] else str(key[0])
            for key in limits.keys()
        ]

        self.var = tk.StringVar(self)
        self.var.set(default)  # Set the default value

        self.current_increment, self.current_interval = self.get_increment_interval(
            self.var.get()
        )

        self.option_menu = ttk.Combobox(
            self, textvariable=self.var, values=self.intervals, width=10
        )
        self.option_menu.pack(side="left")

        self.decrement_button = tk.Button(self, text="-", command=self.decrement_value)
        self.decrement_button.pack(side="left")

        self.increment_button = tk.Button(self, text="+", command=self.increment_value)
        self.increment_button.pack(side="left")

        self.option_menu.bind("<<ComboboxSelected>>", self.update_display)

    def update_increment(self, selected_interval) -> None:
        self.current_interval = selected_interval
        self.increment = self.limits[selected_interval]

    def update_display(self, event) -> None:
        int_string = self.var.get()
        min_value = int_string.split("-")[0]
        self.var.set(min_value)

    def get_increment_interval(self, current_value: float) -> tuple:
        increment = 0
        if current_value == "No Data":
            return None, None
        for intervals in self.limits.keys():
            inc = self.limits[intervals]
            if inc:
                interval = arange(
                    float(intervals[0]), float(intervals[1] + inc), float(inc)
                )
                if float(current_value) in interval:
                    increment = inc
                    return increment, intervals
            else:
                if current_value == intervals[0]:
                    increment = inc
                    return inc, intervals

    def get_next_increment_interval(self, current_interval: tuple) -> tuple:
        try:
            index = self.interval_list.index(self.current_interval) + 1
            return self.increment_list[index], self.interval_list[index]
        except IndexError:
            return None, None
        except ValueError:
            return None, None

    def increment_value(self) -> None:
        if self.var.get() == "No Data":
            self.current_interval = self.interval_list[0]
            self.current_increment = self.increment_list[0]
            self.var.set(self.current_interval[0])
            return
        current_value = float(self.var.get())
        next_increment, next_interval = self.get_next_increment_interval(
            self.current_interval
        )
        if current_value + self.current_increment > self.current_interval[1]:
            self.current_increment, self.current_interval = (
                next_increment,
                next_interval,
            )
            current_value = self.current_interval[0]
            if current_value is None:
                current_value = self.var.get()
        else:
            current_value += self.current_increment
            if next_interval is not None and current_value == next_interval[0]:
                self.current_increment, self.current_interval = (
                    next_increment,
                    next_interval,
                )
        self.var.set(str(round(current_value, 1)))

    def decrement_value(self) -> None:
        pass

    @property
    def get(self) -> float:
        return self.var.get()
