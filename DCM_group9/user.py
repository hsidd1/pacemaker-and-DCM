"""User class for storing user information and pacing mode parameters."""
from __future__ import annotations

class User:
    def __init__(self, username: str, password: str, data: dict = None):
        """Initializes User class with username, password and pacing mode parameters.
        :param username: username of the user
        :param password: password of the user
        :param data: pacing mode parameters of the user
        """
        self.username = username
        self.password = password
        if data:
            self.parameter_dict = data
        else:
            # TODO: update R type modes in assignment 2
            self.parameter_dict = {
                "AOO": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Atrial Amplitude": 3.5,
                    "Atrial Pulse Width": 15, 
                    "Atrial Sensitivity": 2.5,
                },
                "AAI": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Atrial Amplitude": 3.5,
                    "Atrial Pulse Width": 15, 
                    "Atrial Sensitivity": 2.5,
                    "ARP": 250,
                },
                "VOO": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Ventricular Amplitude": 3.5,
                    "Ventricular Pulse Width": 15, 
                    "Ventricular Sensitivity": 12, 
                },
                "VVI": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Ventricular Amplitude": 3.5,
                    "Ventricular Pulse Width": 15, 
                    "Ventricular Sensitivity": 12, 
                    "VRP": 320,
                },
                "AOOR": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Atrial Amplitude": 3.5,
                    "Atrial Pulse Width": 15, 
                    "Atrial Sensitivity": 2.5,

                },
                "AAIR": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Atrial Amplitude": 3.5,
                    "Atrial Pulse Width": 15, 
                    "Atrial Sensitivity": 2.5,
                    "ARP": 250,
                },
                "VOOR": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Ventricular Amplitude": 3.5,
                    "Ventricular Pulse Width": 15, 
                    "Ventricular Sensitivity": 12, 

                },
                "VVIR": {
                    "Lower Rate Limit": 60,
                    "Upper Rate Limit": 120,
                    "Ventricular Amplitude": 3.5,
                    "Ventricular Pulse Width": 15, 
                    "Ventricular Sensitivity": 12, 

                },
            }

    def __repr__(self) -> str:
        """for printing"""
        return f"User with username: {self.username} and password: {self.password}"

    def to_dict(self) -> dict:
        """for *json* file writing
        :return: dictionary with username, password and pacing mode parameters of the user
        """
        return {
            self.username: {
                "password": self.password,
                "pacing_mode_params": self.parameter_dict,
            }
        }

    def update_parameters(self, data: dict, pacing_mode: str = None):
        """Updates pacing mode parameters of the user.
        :param data: pacing mode parameters of the user
        :param pacing_mode: pacing mode of the user
        """
        if pacing_mode:
            self.parameter_dict[pacing_mode] = data
        else:
            self.parameter_dict = data
