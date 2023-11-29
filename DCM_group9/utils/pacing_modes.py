from enum import Enum
import numpy as np
class PaceMode(Enum):
    OFF = np.uint8(0)
    DDD = np.uint8(252)
    VDD = np.uint8(188)
    DDI = 3310
    DOO = 3000
    AOO = np.uint8(64)
    AAI = np.uint8(84)
    VOO = np.uint8(128)
    VVI = np.uint8(164)
    AAT = 1120
    VVT = 2220
    DDDR = 3331
    VDDR = 2331
    DDIR = 3311
    DOOR = 3001
    AOOR = np.uint8(65)
    AAIR = np.uint8(85)
    VOOR = np.uint8(129)
    VVIR = np.uint8(165)

    def __str__(self):
        return self.name
    
    def __int__(self):
        return self.value
    
    def encode(pacing_mode: str):
        match pacing_mode:
            case "AOO":
                return PaceMode.AOO.value
            case "AAI":
                return PaceMode.AAI.value
            case "VOO":
                return PaceMode.VOO.value
            case "VVI":
                return PaceMode.VVI.value
            case "AOOR":
                return PaceMode.AOOR.value
            case "AAIR":
                return PaceMode.AAIR.value
            case "VOOR":
                return PaceMode.VOOR.value
            case "VVIR":
                return PaceMode.VVIR.value

