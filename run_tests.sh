#!/bin/bash
# Tests for DCM application automated with GitHub Actions

# Set up the Python environment
python -m pip install --upgrade pip
pip install flake8 pytest
if [ -f requirements.txt ]; then pip install -r requirements.txt; fi

# Run the tests from the tests directory
cd DCM_group9
# Running as a module
python -m tests.test_login
