import pytest

import sys
import tkinter as tk
sys.path.append('..')
from DCM_group9.pacing_parameters import PacingParameters
from DCM_group9.custom_widgets import FunkyWidget
sys.path.remove('..')

class TestPacingParameters:
    def test_init(self):
        name = "Lower Rate Limit"
        valid_interval_map = {(30, 50): 5, (50, 90): 1, (90, 175): 5}
        unit = "ppm"
        pacing_parameters = PacingParameters(name, valid_interval_map, unit)
        assert pacing_parameters.name == name
        assert pacing_parameters.valid_interval_map == valid_interval_map
        assert pacing_parameters.unit == unit


@pytest.fixture
def funky_widget():
    screen = tk.Tk()
    limits = {
        (0, 10): 1.0,
        (11, 20): 2.0,
    }
    default = 5.0
    widget = FunkyWidget(screen, limits, default)
    return widget


def test_get_next_increment_interval(funky_widget):
    # Test getting the next increment and interval
    inc, intervals = funky_widget.get_next_increment_interval((0, 10))
    assert inc == 2.0
    assert intervals == (11, 20)

def test_get_increment_interval(funky_widget):
    # Test getting the increment and interval for a given value
    inc, intervals = funky_widget.get_increment_interval(7.5)
    # assert inc == 1.0
    # assert intervals == None

def test_get_previous_increment_interval(funky_widget):
    # Test getting the previous increment and interval
    inc, intervals = funky_widget.get_previous_increment_interval((11, 20))
    assert inc == 2.0
    assert intervals == (11, 20)


   

if __name__ == "__main__":
    pytest.main(["-vv", "-s", "test_pacing_parameters.py::TestPacingParameters::test_init"])
 
