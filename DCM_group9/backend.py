"""This module contains the backend class for the DCM group 9 project.

For assignment 1, this class is used to check communication status"""
import serial


class Backend:
    def __init__(self, port: str = None):
        """Initializes Backend class with serial port.
        :param port: serial port
        """
        if port is None:
            # empty connection
            self.ser = serial.Serial()
        else:
            self.ser = serial.Serial(port, 115200, timeout=1)
            self.ser.flush()

    @property
    def is_connected(self) -> bool:
        """Checks if serial port is open.
        :return: True if serial port is open, False otherwise
        """
        return self.ser.is_open
