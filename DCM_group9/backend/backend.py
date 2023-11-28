"""Contains the backend class for the DCM app.

Utilizes serial communication for transmission and receiving of data from the pacemaker."""
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
        self.egram_data = [(0,0)]*6000
        self.transmit_params = True
        self.banned_ports = []
        self.ser = serial.Serial()

        """
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

    # create a thread that attempts open all available com ports, if 
    # port is valid a connection is established 
    def open_port(self, current_screen):
        serial_data = []
        serial_data.append(START_TRANSMISSION_BYTE)
        serial_data.append(START_TRANSMISSION_BYTE)
        all_ports = []

        for num in range(14):
            serial_data.append(START_TRANSMISSION_BYTE)
        packed_serial_data = struct.pack('16i', *serial_data)

        while current_screen[0]:
            ports = list_ports.comports()
            ports_difference = [port for port in ports if port not in self.banned_ports]
            ports_names = [port.device for port in ports_difference]
            for port in ports_difference:
                if port not in all_ports:
                    all_ports.append(port)
                if not self.ser.is_open:
                    self.transmit_params = True
                    print("Attemping to connect to: ", port.device)
                    try:
                        self.ser = serial.Serial(port.device, 115200, timeout=1, write_timeout=1)
                        data = bytearray()
                        self.ser.write(packed_serial_data)
                        self.__flush()
                        time.sleep(0.1)
                        for _ in range(8):
                            chunk = self.ser.read(8)
                            if not chunk:
                                self.ser.close()
                                break
                            data.extend(chunk)
                        if len(data) != len(packed_serial_data):
                            self.banned_ports.append(port)
                            self.ser.close()
                            print("goodbye")
                            continue
                        serial_data = struct.unpack('<16i', data)
                        succed = False
                        for index, byte in enumerate(serial_data):
                            if serial_data[index] == START_TRANSMISSION_BYTE:
                                succed = True
                        if not succed:
                            self.banned_ports.append(port)
                            self.ser.close()
                            print("oh no!")
                            continue
                        print("connected to port: ", port)
                        self.transmit_params = False
                        break
                    except Exception as e:
                        print(e)
                        self.banned_ports.append(port)
                        self.ser.close()
                        pass
            if self.ser.port not in ports_names and self.ser.is_open:
                print("hello")
                self.transmit_params = True
                self.ser.close()

            time.sleep(0.01)

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
        i = -1
        while current_screen[0]:
            if self.is_connected:
                try:
                    while not self.transmit_params:
                        # Read data from serial port
                        data = self.ser.read(8)

                        if not data:
                            break

                        # Data for time and voltage TODO: change in a2 to match expected transfer
                        v_vector = struct.unpack('<2i', data)
                        if i != 5999:
                            i = i + 1
                            self.egram_data[i] = (float(v_vector[0]/10000), float(v_vector[1]/10000))
                        else:
                            for k in range(len(self.egram_data)-1):
                                self.egram_data[k] = self.egram_data[k + 1]
                            self.egram_data[-1] = (float(v_vector[0]/10000), float(v_vector[1]/10000))
                except serial.SerialException:
                    #print("Error: Failed to open the serial port.")
                    pass
                except ValueError:
                    print("Error: Invalid data received from the serial port.")
            else:
                time.sleep(1)

    def __flush(self):
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
        data = bytearray()
        serial_data_start.append(START_TRANSMISSION_BYTE)
        serial_data_confirmed.append(CONFIRMATION_TRANSMISSION_BYTE)

        st = struct.Struct('<16i')
        serial_data_start.append(int(PaceMode.encode(pacing_mode)))
        serial_data_confirmed.append(CONFIRMATION_TRANSMISSION_BYTE)

        for param in params:
            serial_data_start.append((int)(params[param]*10))
            serial_data_confirmed.append(CONFIRMATION_TRANSMISSION_BYTE)
            #print(param)

        packed_data_start = st.pack(*serial_data_start)
        packed_data_confirmed = st.pack(*serial_data_confirmed)
        #print(serial_data)
        #print(packed_data)

        if not self.is_connected:
            raise Exception("Connect the board")
        
        self.__flush()
        verification = False

        try:
            while not verification:
                data = bytearray()
                self.ser.write(packed_data_start)
                self.__flush()
                time.sleep(0.1)
                for _ in range(8):
                    chunk = self.ser.read(8)
                    data.extend(chunk)
                verification = True
                for index, byte in enumerate(packed_data_start):
                    if byte == data[index]:
                        continue
                    else:
                        verification = False
                        break
            self.ser.write(packed_data_confirmed)
            print("!!!")

                    

        except Exception as e:
            print(traceback.format_exc())
            return
        
        self.transmit_params = False

    def chunk_data(self, data, chunk_size):
        """Yield successive n-sized chunks from data."""
        for i in range(0, len(data), chunk_size):
            yield data[i:i + chunk_size]

    def plot_egram(eg_dict) -> None:
        """ takes in egram dict using get_egram_dict and plots it"""
        ax, fig = plt()
