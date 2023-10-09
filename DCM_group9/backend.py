import serial

class Backend:
    def __init__(self, port: str = None):
        if port is None:
            # empty connection
            self.ser = serial.Serial()
        else:
            self.ser = serial.Serial(port, 115200, timeout=1)
            self.ser.flush()

    @property
    def is_connected(self) -> bool:
        return self.ser.is_open