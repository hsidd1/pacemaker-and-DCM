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
            self.parameter_dict = {
                "AOO": {
                    "l_rate_limit": "No Data",
                    "u_rate_limit": "No Data",
                    "atrial_amplitude": "No Data",
                    "atrial_pulse_width": "No Data",
                },
                "AAI": {
                    "l_rate_limit": "No Data",
                    "u_rate_limit": "No Data",
                    "atrial_amplitude": "No Data",
                    "atrial_pulse_width": "No Data",
                    "ARP": "No Data",
                },
                "VOO": {
                    "l_rate_limit": "No Data",
                    "u_rate_limit": "No Data",
                    "vent_amplitude": "No Data",
                    "vent_pulse_width": "No Data",
                },
                "VVI": {
                    "l_rate_limit": "No Data",
                    "u_rate_limit": "No Data",
                    "vent_amplitude": "No Data",
                    "vent_pulse_width": "No Data",
                    "VRP": "No Data",
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
