"""This module contains the backend class for the DCM group 9 project.

For assignment 1, this class is used to check communication status"""
import serial
from serial.tools import list_ports

class Backend:
    def __init__(self, port: str = None, device_id: str = None):
        """Initializes Backend class with serial port.
        :param port: serial port
        """
        self.device_id = device_id
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
    
    @property
    def board_connected(self) -> str:
        """Checks what board is connected.
        :return: str of board connected
        """
        VID = 1234
        PID = 5678

        device_list = list_ports.comports()
        for device in device_list:
            if (device.vid != None or device.pid != None):
                if ('{:04X}'.format(device.vid) == VID and
                    '{:04X}'.format(device.pid) == PID):
                    self.device_id = device.device
                    break
                self.device_id = None
        return self.device_id
