import json

config = "DCM_group9/config.json"

class AccessibilityConfig:
    def __init__(self):
        self._font_size = None
        self._colour_mode = None
        self.__get_settings_from_file()

        self.display_names = {
            "_font_size": "Font Size",
            "_colour_mode": "Colour Mode"
        }

    @property
    def font_size(self):
        return self._font_size
    
    @font_size.setter
    def font_size(self, value):
        self._font_size = value
        self.__write_settings_to_file()
    
    @property
    def colour_mode(self):
        return self._colour_mode
    
    @colour_mode.setter
    def colour_mode(self, value):
        self._colour_mode = value
        self.__write_settings_to_file()

    def __get_settings_from_file(self):
        try:
            with open(config, "r") as f:
                try:
                    data = json.load(f)
                except json.JSONDecodeError:
                    data = []
        except FileNotFoundError:
            with open(config, "w") as f:
                pass           

    def __write_settings_to_file(self):
        pass

    def get_settings(self):
        attributes = dir(self)
        settings = []
        for attribute in attributes:
            try:
                settings.append(self.display_names[attribute])
            except KeyError:
                pass
        return settings