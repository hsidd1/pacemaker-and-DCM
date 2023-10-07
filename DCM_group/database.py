from user import User
DATABASE = "DCM_group/database.txt"

class Database:
    """Database class to store Users"""
    def __init__(self, database: str = DATABASE):
        self.database = database
        # map of users' usernames and passwords
        # read from file to see who exists and add them to map each run
        with open(self.database, "r") as f:
            self.users_map = {line.split()[0]: line.split()[1] for line in f.readlines() if line}

    def get_user_count(self) -> int:
        """returns number of users in database"""
        return len(self.users_map)

    def __add_user(self, user: User):
        """Private method - adds user to database"""
        self.users_map[user.username] = user.password

    def __remove_user(self, username: str):
        """Private method - removes user from database"""
        del self.users_map[username]

    def write_to_file(self, user: User):
        """writes user to database when registered"""
        self.__add_user(user)
        if not user in self.users_map:
            with open(self.database, "a") as f:
                f.write(f"{user.user_string()}\n")