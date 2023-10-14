import pytest
import sys

sys.path.append("..")
from DCM_group9.app import Application

sys.path.remove("..")


def test_app():
    # App should be created without any errors
    app = Application()
    assert app != None


if __name__ == "__main__":
    pytest.main(["-v", "-s", "test_app.py"])
