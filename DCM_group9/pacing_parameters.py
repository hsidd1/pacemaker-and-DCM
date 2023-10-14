"""Contains the class PacingParameters, used to handle the pacing parameters."""
from enum import Enum
from collections import OrderedDict

# Parameter intervals and increments
L_RATE_INT = OrderedDict([((30, 50), 5), ((50, 90), 1), ((90, 175), 5)])

U_RATE_INT = OrderedDict([((50, 175), 5)])

AMPLITUDE_INT = OrderedDict([((0, 0), 1), ((0.5, 3.2), 0.1), ((3.5, 7.0), 0.5)])

PULSE_WIDTH_INT = OrderedDict([((0.05, 0.05), 1), ((0.1, 1.9), 0.1)])

ARP_INT = OrderedDict([((150, 500), 10)])

VRP_INT = OrderedDict([((150, 500), 10)])


class PacingParameters:
    def __init__(self, name: str, valid_interval_map: dict, unit: str = ""):
        """Initializes PacingParameters class with name, valid interval map and unit.
        :param name: name of pacing parameter
        :param valid_interval_map: valid interval map of pacing parameter
        :param unit: unit of pacing parameter
        """
        self.name = name
        self.valid_interval_map = valid_interval_map
        self.unit = unit


class Parameters(Enum):
    """Enum class for pacing parameters."""
    LOWER_RATE_LIMIT = PacingParameters("Lower Rate Limit", L_RATE_INT, "ppm")
    UPPER_RATE_LIMIT = PacingParameters("Upper Rate Limit", U_RATE_INT, "ppm")
    ATRIAL_AMPLITUDE = PacingParameters("Atrial Amplitude", AMPLITUDE_INT, "V")
    ATRIAL_PULSE_WIDTH = PacingParameters("Atrial Pulse Width", PULSE_WIDTH_INT, "msec")
    ARP = PacingParameters("ARP", ARP_INT, "msec")
    VENTRICULAR_AMPLITUDE = PacingParameters("Ventricular Amplitude", AMPLITUDE_INT, "V")
    VENTRICULAR_PULSE_WIDTH = PacingParameters(
        "Ventricular Pulse Width", PULSE_WIDTH_INT, "msec"
    )
    VRP = PacingParameters("VRP", VRP_INT, "msec")
