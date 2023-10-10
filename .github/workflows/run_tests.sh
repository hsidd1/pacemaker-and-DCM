#!/bin/bash

# Set up the Python environment
python -m pip install --upgrade pip
pip install flake8 pytest
if [ -f requirements.txt ]; then pip install -r requirements.txt; fi

# Run the tests from the tests directory
cd DCM_group9
python -m tests.test_login
