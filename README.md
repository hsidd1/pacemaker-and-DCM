# pacemaker-and-DCM
<img src="DCM_group9/imgs/heartLogo.png" alt="Logo" width="50" height="50">


![Supported Python Versions](https://img.shields.io/badge/supported%20python%20versions-3.10%20%7C%203.11-blue) [![Code Style](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black) [![Tests](https://github.com/pylint-dev/pylint/actions/workflows/tests.yaml/badge.svg?branch=main)](https://github.com/hsidd1/pacemaker-and-dcm/actions)
 [![Docs Passing](https://img.shields.io/badge/docs-passing-brightgreen)](docs_group9/) [![Linting](https://img.shields.io/badge/linting-pylint-yellowgreen)](https://github.com/pylint-dev/pylint) 





A Pacemaker system modelled in Simulink with a corresponding DCM application

### Usage 

First, clone the repository and navigate to the project directory:
```sh 
git clone https://github.com/hsidd1/pacemaker-and-DCM
cd pacemaker-and-DCM
```

#### Running the DCM application 
To run the Device Controller-Monitor application, you will need
 [Python](https://www.python.org/downloads/) (3.10 or above) as well as 
the packages outlined in the requirements file:

```sh
python -m pip install -r DCM_group9/requirements.txt
``` 

Then the application can be started from the same directory:
```sh
python DCM_group9/app.py
```
##### Running Tests
Tests are run using `pytest` automatically with Python 3.11 in an Ubuntu-latest environment via automated Github Actions CI/CD. 

To run tests locally: 
```sh
./run_tests.sh
```

#### Using the Pacemaker


<!---
#### Contributors
add your credits here
-->
