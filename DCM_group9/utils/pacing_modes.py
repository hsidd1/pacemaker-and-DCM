from enum import Enum

class PaceMode(Enum):
    OFF = 0
    DDD = 3330
    VDD = 2330
    DDI = 3310
    DOO = 3000
    AOO = 1000
    AAI = 1110
    VOO = 2000
    VVI = 2210
    AAT = 1120
    VVT = 2220
    DDDR = 3331
    VDDR = 2331
    DDIR = 3311
    DOOR = 3001
    AOOR = 1001
    AAIR = 1111
    VOOR = 2001
    VVIR = 2211

    def __str__(self):
        return self.name
    
    def __int__(self):
        return self.value
    
    def decode(pacing_mode: str):
        match pacing_mode:
            case "AOO":
                return PaceMode.AOO
            case "AAI":
                return PaceMode.AAI
            case "VOO":
                return PaceMode.VOO
            case "VVI":
                return PaceMode.VVI
            case "AOOR":
                return PaceMode.AOOR
            case "AAIR":
                return PaceMode.AAIR
            case "VOOR":
                return PaceMode.VOOR
            case "VVIR":
                return PaceMode.VVIR
