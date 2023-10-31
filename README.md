# pacemaker-and-DCM
<img src="DCM_group9/imgs/heartLogo.png" alt="Logo" width="50" height="50">


![Supported Python Versions](https://img.shields.io/badge/supported%20python%20versions-3.10%20%7C%203.11-blue) [![Code Style](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black) [![Tests](https://github.com/pylint-dev/pylint/actions/workflows/tests.yaml/badge.svg?branch=main)](https://github.com/hsidd1/pacemaker-and-dcm/actions)
 [![Docs Passing](https://img.shields.io/badge/docs-passing-brightgreen)](docs_group9/) [![Linting](https://img.shields.io/badge/linting-pylint-yellowgreen)](https://github.com/pylint-dev/pylint) 
<a href="https://github.com/hsidd1/pacemaker-and-dcm/blob/main/LICENSE"><img alt="License: MIT" src="https://black.readthedocs.io/en/stable/_static/license.svg"></a>




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
./DCM_group9/scripts/run_tests.sh
# Optionally, add flag to generate logs
./DCM_group9/scripts/run_tests.sh -html
```

#### Using the Pacemaker
[MATLAB R2022b (or higher)](https://www.mathworks.com/products/matlab.html) with Simulink is required along with the following add-ons:
- Embedded Coder
- Fixed-Point Designer
- MATLAB Coder
- Simulink Check
- Simulink Coder
- Simulink Coverage
- Simulink Design Verifier
- Simulink Desktop Real-Time
- Simulink Test
- Stateflow

The [Simulink Coder Support Package for NXP FRDM-K64F Board](https://www.mathworks.com/matlabcentral/fileexchange/55318-simulink-coder-support-package-for-nxp-frdm-k64f-board) will also need to be installed.

Additionally, [HeartView](https://github.com/theguymeyer/heartview) is also required along with the NXP FRDM-K64F board to act as the pacemaker, and Nucleo F446RE to act as the heart.

The [Simulink model](https://github.com/hsidd1/pacemaker-and-DCM/blob/main/simulink_group9/Assignment_1_Simulink.slx) will need to be opened and the heart and pacemaker will need to be connected to your computer via USB.

Within the Simulink model, the desired pacing mode can be chosen along with other parameters, and the result of the heart signal can be viewed in HeartView once the heart characteristics have been specified.
<!---
#### Contributors
add your credits here
-->
