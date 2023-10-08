class User:
    """User class to store username and password
       possibly extend to store pacemaker data"""
    def __init__(self, username: str, password: str):
        self.username = username
        self.password = password

    def user_string(self) -> str:
        """for *text* file writing"""
        return f"{self.username}\t{self.password}"
    
    def __str__(self) -> str:
        """for printing"""
        return f"User with username: {self.username} and password: {self.password}"
    
    def to_dict(self) -> dict:
        """for *json* file writing"""
        return {"username": self.username, "password": self.password}