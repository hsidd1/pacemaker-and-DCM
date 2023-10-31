#!/bin/bash
# Tests for DCM application automated with GitHub Actions

# Ensure database contains default content for each test
DATABASE_FILE="DCM_group9/tests/test_database.json"
DEFAULT_DATABASE="DCM_group9/tests/default_database.json"

> "$DATABASE_FILE"
cp "$DEFAULT_DATABASE" "$DATABASE_FILE"

# Run the tests from the tests directory
cd DCM_group9

# check html report flag
if [ "$1" == "-html" ]; then
     python -m tests.test_login --html=tests/logs/pytest_report.html --self-contained-html

else
    python -m tests.test_login
fi
