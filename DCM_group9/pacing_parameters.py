""" This file contains the class PacingParameters, which is used to handle the pacing parameters.

To be used in assignment 2."""
from enum import Enum

l_rate_int = {
    (30, 50) : 5,
    (50, 90) : 1,
    (90, 175) : 5
}

u_rate_int = {
    (50,175) : 5
}

amplitude_int = {
    (0,0) : 0,
    (0.5, 3.2) : 0.1,
    (3.5, 7.0) : 0.5
}

pulse_width_int = {
    (0.05, 0.05) : 0,
    (0.1, 1.9) : 0.1
}

arp_int = {
    (150,500) : 10
}

vrp_int = {
    (150,500) : 10
}

class PacingParameters:
    def __init__(self, name: str, valid_interval_map: dict, unit: str = ""):
        self.name = name
        self.valid_interval_map = valid_interval_map
        self.unit = unit

class Parameters(Enum):
    LOWER_RATE_LIMIT = PacingParameters("Lower Rate Limit", l_rate_int, "ppm")
    UPPER_RATE_LIMIT = PacingParameters("Upper Rate Limit", u_rate_int, "ppm")
    ATRIAL_AMPLITUDE = PacingParameters("Atrial Amplitude", amplitude_int, "V")
    ATRIAL_PULSE_WIDTH = PacingParameters("Atrial Pulse Width", pulse_width_int, "msec")
    ARP = PacingParameters("ARP", arp_int, "msec")
    VENTRICULAR_AMPLITUDE = PacingParameters("Ventricular Amplitude", amplitude_int, "V")
    VENTRICULAR_PULSE_WIDTH = PacingParameters("Ventricular Pulse Width", pulse_width_int, "msec")
    VRP = PacingParameters("VRP", vrp_int, "msec")