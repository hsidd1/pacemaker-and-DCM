"""This module contains the backend class for the DCM group 9 project.

For assignment 1, this class is used to check communication status"""
import serial
from serial.tools import list_ports

class Backend:
    def __init__(self, port: str = None, device_id: str = None):
        """Initializes Backend class with serial port.
        :param port: serial port
        :param device_id: device id of board
        :param previous_device_ids: previous device ids interrogated
        """
        self.device_id = device_id
        self.previous_device_ids = []
        """
        TODO: implement in assignment 2
        with open('device_ids.txt', 'r') as f:
            for line in f:
                self.previous_device_ids.append(line.strip())
        with open('device_ids.txt', 'a') as f:
            if self.device_id not in self.previous_device_ids:
                f.write(self.device_id + '\n')
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
    
    @property
    def board_connected(self) -> str:
        """Checks what board is connected.
        :return: str of board connected
        TODO: check if board connected id is same as previous ids
        by seeing if it is in self.previous_device_ids
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
