from user import User
import json

DATABASE = "DCM_group/database.json"

class Database:
    """Database class to store Users"""
    def __init__(self, database: str = DATABASE):
        self.database = database
        # map of users' usernames and passwords
        # read from file to see who exists and add them to map each run
        self.users_map = self.load_users_from_json()

    def load_users_from_json(self) -> dict:
        users_map = {}
        try:
            with open(self.database, "r") as f:
                try:
                    data = json.load(f)
                except json.JSONDecodeError:
                    data = []
                for user_dict in data:
                    try:
                        username = user_dict.get("username")
                        password = user_dict.get("password")
                        if username and password:
                            users_map[username] = password
                    except json.JSONDecodeError as e:
                        print(f"Error decoding JSON: {e}")
                    except KeyError as e:
                        print(f"KeyError: {e} - Invalid JSON structure")
        except FileNotFoundError:
            print(f"File not found: {self.database}")

        return users_map

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
        with open(self.database, "r") as f:
            try:
                users = json.load(f)
            except json.JSONDecodeError:
                users = []
        users.append(user.to_dict())
        with open(self.database, "w") as f:
            # write the entire list of users to the file
            json.dump(users, f)