import json

config = "DCM_group9/ui_config/config.json"


class AccessibilityConfig:
    def __init__(self):
        self._font_size = 10
        self._colour_mode = "Trichromacy"

        self.settings_map = {
            "_font_size": {"Font Size": [10, 30]},
            "_colour_mode": {
                "Colour Mode": [
                    "Trichromacy",
                    "Protanopia",
                    "Deuteranopia",
                    "Tritanopia",
                ]
            },
        }

        self.default_settings = {"Font Size": 10, "Colour Mode": "Trichromacy"}

        self.colour_map = {
            "Trichromacy": ["#ff0000", "#00FF00"],
            "Protanopia": ["#ffdb58", "#4169e1"],
            "Deuteranopia": ["#ffd700", "#000080"],
            "Tritanopia": ["#dc143c", "#87ceeb"],
        }
        self.__get_settings_from_file()

    @property
    def font_size(self):
        return self._font_size

    @font_size.setter
    def font_size(self, value):
        if value != self._font_size:
            self._font_size = value
            self.__write_settings_to_file()

    @property
    def colour_mode(self):
        return self._colour_mode

    @colour_mode.setter
    def colour_mode(self, value):
        if value != self._colour_mode:
            self._colour_mode = value
            self.__write_settings_to_file()

    def __get_settings_from_file(self):
        try:
            with open(config, "r") as f:
                try:
                    data = json.load(f)
                    self._colour_mode = data["Colour Mode"]
                    self._font_size = data["Font Size"]
                except json.JSONDecodeError:
                    with open(config, "w") as f:
                        json.dump(self.default_settings, f, indent=4)
        except FileNotFoundError:
            try:
                with open(config, "x") as f:
                    json.dump(self.default_settings, f, indent=4)
            except FileNotFoundError:
                print(
                    "!!File not found!! \nIF YOU SEE THIS STDOUT AND ITS NOT FROM A TEST, PLEASE CONTACT THE DEVELOPERS"
                )

    def __write_settings_to_file(self):
        try:
            with open(config, "w") as f:
                try:
                    json.dump(self.__to_dict(), f, indent=4)
                except json.JSONDecodeError:
                    pass
        except FileNotFoundError:
            with open(config, "w") as f:
                json.dump(self.default_settings, f, indent=4)

    def get_settings(self):
        attributes = dir(self)
        settings = []
        for attribute in attributes:
            try:
                settings.append(self.settings_map[attribute])
            except KeyError:
                pass
        return settings

    def __to_dict(self):
        return {"Font Size": self._font_size, "Colour Mode": self._colour_mode}
