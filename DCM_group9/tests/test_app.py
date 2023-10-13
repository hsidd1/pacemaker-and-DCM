import pytest
import sys

sys.path.append("..")
from DCM_group9.application_fsm import ApplicationFSM

sys.path.remove("..")


def test_app():
    # App should be created without any errors
    app = ApplicationFSM()
    assert app != None


if __name__ == "__main__":
    pytest.main(["-v", "-s", "test_app.py"])
