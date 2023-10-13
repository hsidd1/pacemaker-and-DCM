"""Module for User class.

User class stores username, password and pacing mode parameters."""


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
            #TODO: update R type modes in assignment 2
            self.parameter_dict = {
                "AOO": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Atrial Amplitude": "No Data",
                    "Atrial Pulse Width": "No Data",
                },
                "AAI": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Atrial Amplitude": "No Data",
                    "Atrial Pulse Width": "No Data",
                    "ARP": "No Data",
                },
                "VOO": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Ventricular Amplitude": "No Data",
                    "Ventricular Pulse Width": "No Data",
                },
                "VVI": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Ventricular Amplitude": "No Data",
                    "Ventricular Pulse Width": "No Data",
                    "VRP": "No Data",
                },
                "AOOR": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Atrial Amplitude": "No Data",
                    "Atrial Pulse Width": "No Data",
                },
                "AAIR": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Atrial Amplitude": "No Data",
                    "Atrial Pulse Width": "No Data",
                    "ARP": "No Data",
                },
                "VOOR": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Ventricular Amplitude": "No Data",
                    "Ventricular Pulse Width": "No Data",
                },
                "VVIR": {
                    "Lower Rate Limit": "No Data",
                    "Upper Rate Limit": "No Data",
                    "Ventricular Amplitude": "No Data",
                    "Ventricular Pulse Width": "No Data",
                },
            }

    def user_string(self) -> str:
        """for *text* file writing"""
        return f"{self.username}\t{self.password}"

    def __str__(self) -> str:
        """for printing"""
        return f"User with username: {self.username} and password: {self.password}"

    def to_dict(self) -> dict:
        """for *json* file writing"""
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
