"""Contains custom widgets for the GUI."""
from __future__ import annotations

import tkinter as tk
from tkinter import ttk
from numpy import arange


class FunkyWidget(tk.Frame):
    def __init__(
        self,
        screen: tk.Tk,
        limits: dict,
        default: float,
        **kwargs,
    ):
        """Initializes FunkyWidget class with screen, limits and default value.
        :param screen: screen to display the widget on
        :param limits: limits of the widget
        :param default: default value of the widget
        """
        super().__init__(screen, **kwargs)

        self.limits = limits
        self.interval_list = list(self.limits.keys()) 
        self.increment_list = list(self.limits.values())

        self.intervals = [
            f"{key[0]}-{key[1]}" if key[0] != key[1] else str(key[0])
            for key in limits.keys()
        ]

        self.var = tk.StringVar(self)
        try:
            x = round(default, 2)
        except TypeError:
            x = default
        self.var.set(x)  # Set the default value


        try:
            self.current_crement, self.current_interval = self.get_increment_interval(
                self.var.get()
            )
        except TypeError:
            print(self.get_increment_interval(self.var.get()))

        self.option_menu = ttk.Combobox(
            self,
            textvariable=self.var,
            values=self.intervals,
            width=10,
            state="readonly",
        )
        self.option_menu.pack(side="left")

        self.decrement_button = tk.Button(self, text="-", command=self.__decrement_value)
        self.decrement_button.pack(side="left")

        self.increment_button = tk.Button(self, text="+", command=self.__increment_value)
        self.increment_button.pack(side="left")

        self.option_menu.bind("<<ComboboxSelected>>", self.__update_display)

    def __update_increment(self, selected_interval) -> None:
        """Updates the increment of the widget."""
        self.current_interval = selected_interval
        self.increment = self.limits[selected_interval]

    def __update_display(self, event) -> None:
        """Updates the display of the widget."""
        int_string = self.var.get()
        min_value = int_string.split("-")[0]
        self.var.set(min_value)

    def get_increment_interval(self, current_value: float) -> tuple:
        """Gets the increment and interval of the current value.
        :param current_value: current value of the widget
        :return: increment and interval of the current value
        """
        epsilon = 1e-10
        if current_value == "No Data":
            return None, None
        current_value = float(current_value)
        for intervals, inc in self.limits.items():
            start, end = map(float, intervals)
            if current_value >= start and current_value <= end:
                if inc:
                    interval = arange(start, end + inc, inc)
                    if (interval[0]-epsilon) < current_value < (interval[-1]+epsilon):
                        return inc, intervals
                else:
                    return inc, intervals
        return None, None

    def get_next_increment_interval(self, current_interval: tuple) -> tuple:
        """Gets the increment and interval of the next value.
        :param current_interval: current interval of the widget
        :return: increment and interval of the next value
        """
        index = (self.interval_list.index(self.current_interval) + 1) % len(
            self.interval_list
        )
        return self.increment_list[index], self.interval_list[index]

    def get_previous_increment_interval(self, current_interval: tuple) -> tuple:
        """Gets the increment and interval of the previous value.
        :param current_interval: current interval of the widget
        :return: increment and interval of the previous value
        """
        index = (self.interval_list.index(self.current_interval) - 1) % len(
            self.interval_list
        )
        return self.increment_list[index], self.interval_list[index]

    def __increment_value(self) -> None:
        """Increments the value of the widget."""
        epsilon = 1e-10
        if self.var.get() == "No Data":
            self.current_interval = self.interval_list[0]
            self.current_crement = self.increment_list[0]
            self.var.set(self.current_interval[0])
            return

        current_value = float(self.var.get())
        next_increment, next_interval = self.get_next_increment_interval(
            self.current_interval
        )

        # If the current value is at the end of the interval, increment the interval
        if current_value + self.current_crement > self.current_interval[1] + epsilon:
            self.current_crement, self.current_interval = next_increment, next_interval
            if current_value == next_interval[0]:
                current_value += next_increment
            else:
                current_value = next_interval[0]
        else:
            # Increment the current value
            current_value += self.current_crement
            if next_interval is not None and current_value == next_interval[0]:
                self.current_crement, self.current_interval = (
                    next_increment,
                    next_interval,
                )
        self.var.set(str(round(current_value, 2)))

    def __decrement_value(self) -> None:
        """Decrements the value of the widget."""
        epsilon = 1e-10
        if self.var.get() == "No Data":
            self.current_interval = self.interval_list[-1]
            self.current_crement = self.increment_list[-1]
            self.var.set(self.current_interval[1])
            return

        current_value = float(self.var.get())
        next_increment, next_interval = self.get_previous_increment_interval(
            self.current_interval
        )

        if current_value - self.current_crement < self.current_interval[0] - epsilon:
            self.current_crement, self.current_interval = next_increment, next_interval
            if current_value == next_interval[1]:
                current_value -= next_increment
            else:
                current_value = self.current_interval[1]
        else:
            current_value -= self.current_crement
            if current_value == next_interval[1]:
                self.current_crement, self.current_interval = (
                    next_increment,
                    next_interval,
                )
        self.var.set(str(round(current_value, 2)))

    def get(self):
        """Gets the value of the widget."""
        return float(self.var.get())
