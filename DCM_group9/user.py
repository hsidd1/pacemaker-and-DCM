class User:
    """User class to store username and password
       possibly extend to store pacemaker data"""

    def __init__(self, username: str, password: str):
        self.username = username
        self.password = password
        self.__parameter_dict = {
            "AOO": {
                "l_rate_limit": "No Data",
                "u_rate_limit": "No Data",
                "atrial_amplitude": "No Data",
                "atrial_pulse_width": "No Data"
            }, 
            "AAI": {
                "l_rate_limit": "No Data",
                "u_rate_limit": "No Data",
                "atrial_amplitude": "No Data",
                "atrial_pulse_width": "No Data",
                "ARP": "No Data"
            },
            "VOO": {
                "l_rate_limit": "No Data",
                "u_rate_limit": "No Data",
                "vent_amplitude": "No Data",
                "vent_pulse_width": "No Data"
            },
            "VVI": {
                "l_rate_limit": "No Data",
                "u_rate_limit": "No Data",
                "vent_amplitude": "No Data",
                "vent_pulse_width": "No Data",
                "VRP": "No Data"
            }
        }

    def user_string(self) -> str:
        """for *text* file writing"""
        return f"{self.username}\t{self.password}"
    
    def __str__(self) -> str:
        """for printing"""
        return f"User with username: {self.username} and password: {self.password}"
    
    def to_dict(self) -> dict:
        """for *json* file writing"""
        return {self.username: {"password": self.password, "pacing_mode_params": self.__parameter_dict}}
    
    def update_parameters(self, pacing_mode: str, data: dict):
        self.__parameter_dict[pacing_mode] = data