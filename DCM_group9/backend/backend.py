"""Contains the backend class for the DCM app.

For assignment 1, this class is used to set up future functionalities."""
from __future__ import annotations

import serial
from serial.tools import list_ports
import json
import matplotlib.pyplot as plt
import traceback
import struct
import time
from utils.pacing_modes import PaceMode
from threading import Thread

from random import Random
   
START_TRANSMISSION_BYTE = 0x11111100
CONFIRMATION_TRANSMISSION_BYTE = 0x11111111

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
        self.egram_data = [0]*10000
        self.transmit_params = False

        self.ser = serial.Serial()
        #self.p2 = Process(target=self.__open_port())
        #self.p.start()
        # self.p.join()

        """
        TODO: implement in assignment 2
        with open('device_ids.txt', 'r') as f:
            for line in f:
                self.previous_device_ids.append(line.strip())
        with open('device_ids.txt', 'a') as f:
            if self.device_id not in self.previous_device_ids:
                f.write(self.device_id + '\n')
        """
        # if self.port is None:
        #     # empty connection
        #     self.ser = serial.Serial()
        # else:
        #     self.ser = serial.Serial(port, 115200, timeout=1)
        #     self.ser.flush()

    # create a thread that opens your com port 
# and reads the data from it
    def open_port(self, current_screen):
        while current_screen[0]:
            #print(self.ser.is_open)
            for port in list_ports.comports():
                if not self.ser.is_open:
                    try:
                        self.ser = serial.Serial("COM7", 115200, timeout=1)
                        print("connected to port: ", port)
                        break
                    except Exception:
                        print("Error: Failed to open the serial port.")
                        pass
            if not list_ports.comports() and self.ser.is_open:
                print("hello")
                self.ser = serial.Serial()
            time.sleep(1)

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

    def get_egram_data(self, current_screen):
        """Gets the egram data from the serial port.
        :return: dictionary of egram data"""
        i = 0
        while current_screen[0]:
            if self.is_connected:
                try:
                    while not self.transmit_params:
                        # Read data from serial port
                        data = self.ser.read(8)

                        if not data:
                            break

                        # Data for time and voltage TODO: change in a2 to match expected transfer
                        self.egram_data[i] = struct.unpack('<2i', data)
                        i = i + 1

                        if i == 10000:
                            i = 0
                except serial.SerialException:
                    print("Error: Failed to open the serial port.")
                except ValueError:
                    print("Error: Invalid data received from the serial port.")

    def __flush(self, ser: Backend):
        self.ser.flush()
        self.ser.reset_input_buffer()
        self.ser.reset_output_buffer()

    def transmit_parameters(self, pacing_mode: str, params: dict) -> None:
        """ transmits data to pacemaeker
        :param data: data to be communicated over uart
        """
        self.transmit_params = True
        serial_data_start = []
        serial_data_confirmed = []
        serial_data_start.append(START_TRANSMISSION_BYTE)
        serial_data_confirmed.append(CONFIRMATION_TRANSMISSION_BYTE)

        st = struct.Struct('15i')
        serial_data_start.append(int(PaceMode.decode(pacing_mode)))
        serial_data_confirmed.append(int(PaceMode.decode(pacing_mode)))
        for param in params:
            serial_data_start.append((int)(params[param]*10))
            serial_data_confirmed.append((int)(params[param]*10))
            #print(param)

        packed_data_start = st.pack(*serial_data_start)
        packed_data_confirmed = st.pack(*serial_data_confirmed)
        #print(serial_data)
        #print(packed_data)

        if not self.is_connected:
            raise Exception("Connect the board")
        
        self.__flush(self.ser)
        verification = False

        try:
            while not verification:
                self.ser.write(packed_data_start)
                data = self.ser.read(15*4)
                verification = True
                for index, byte in enumerate(packed_data_start):
                    if byte == data[index]:
                        continue
                    else:
                        verification = False

            self.ser.write(packed_data_confirmed)
                    

        except Exception as e:
            print(traceback.format_exc())
            return
        
        self.transmit_params = False

    def plot_egram(eg_dict) -> None:
        """ takes in egram dict using get_egram_dict and plots it"""
        ax, fig = plt()
