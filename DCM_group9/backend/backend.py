"""Contains the backend class for the DCM app.

For assignment 1, this class is used to set up future functionalities."""
from __future__ import annotations

import serial
from serial.tools import list_ports
import json
import matplotlib.pyplot as plt
import traceback
import struct

class Backend:
    def __init__(self, port: str = None, device_id: str = None):
        """Initializes Backend class with serial port.
        :param port: serial port
        :param device_id: device id of board
        :param previous_device_ids: previous device ids interrogated
        """
        self.port = port
        self.device_id = device_id
        self.previous_device_ids = []

        ports = list(list_ports.comports())
        for p in ports:
            print (p)
        """
        TODO: implement in assignment 2
        with open('device_ids.txt', 'r') as f:
            for line in f:
                self.previous_device_ids.append(line.strip())
        with open('device_ids.txt', 'a') as f:
            if self.device_id not in self.previous_device_ids:
                f.write(self.device_id + '\n')
        """
        if self.port is None:
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
            if device.vid != None or device.pid != None:
                if (
                    "{:04X}".format(device.vid) == VID
                    and "{:04X}".format(device.pid) == PID
                ):
                    self.device_id = device.device
                    break
                self.device_id = None
        return self.device_id

    def get_egram_dict(self) -> dict:
        """Gets the egram data from the serial port.
        :return: dictionary of egram data"""
        egram_data = {}

        if self.is_connected:
            try:
                while True:
                    # Read data from serial port
                    data = self.ser.readline().decode().strip()

                    if not data:
                        break

                    # Data for time and voltage TODO: change in a2 to match expected transfer
                    time, voltage = map(float, data.split(","))
                    egram_data[time] = voltage

                self.ser.close()
            except serial.SerialException:
                print("Error: Failed to open the serial port.")
            except ValueError:
                print("Error: Invalid data received from the serial port.")

        return egram_data

    def __flush(self, ser: Backend):
        self.ser.flush()
        self.ser.reset_input_buffer()
        self.ser.reset_output_buffer()

    def transmit_parameters(self, data: json) -> None:
        """ transmits data to pacemaeker
        :param data: data to be communicated over uart
        """
        if not self.is_connected:
            raise Exception("Connect the board")
        st = struct.Struct('i')
        packed_data = st.pack(data)
        print(sys.getsizeof(packed_data))
        f = open("output.json", "w")
        f.write(data)
        f.close()


        self.__flush(self.ser)
        try:
            
            self.ser.write(packed_data)
        except Exception as e:
            print(traceback.format_exc())
            return

    def plot_egram(eg_dict) -> None:
        """ takes in egram dict using get_egram_dict and plots it"""
        ax, fig = plt()

        