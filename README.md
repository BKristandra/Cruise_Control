# Simple Cruise Control Project

## Description
This project implements a simplified cruise control system for vehicles using a [PID controller](https://tttapa.github.io/Pages/Arduino/Control-Theory/Motor-Fader/PID-Controllers.html). The goal is to regulate the car's velocity to a user-defined target value by compensating for resistances like rolling resistance and aerodynamic drag. These resistances are [modeled linearly](https://ctms.engin.umich.edu/CTMS/index.php?example=CruiseControl&section=SimulinkModeling) for simplicity, enabling efficient simulation and control design.

Upon running the program, the user will be prompted to input a simulation time, the number of steps the time should be broken down into and a target velocity.
The output will be a velocity timeseries vector. This vector is a breakdown of the velocity versus time steps to showcase the controller's behavior over simulation time.


## Dependencies
* Matplot++ for visuaĺization purpose (included in CMakeLists.txt)

## Installation
<!-- Within a particular ecosystem, there may be a common way of installing things, such as using Yarn, NuGet, or Homebrew. However, consider the possibility that whoever is reading your README is a novice and would like more guidance. Listing specific steps helps remove ambiguity and gets people to using your project as quickly as possible. If it only runs in a specific context like a particular programming language version or operating system or has dependencies that have to be installed manually, also add a Requirements subsection. -->
To work on this project, you will need a C++ development environment set up on your machine. Follow these steps to clone the repository, compile the code, and run the algorithm:

### Clone the Repository 
Open a terminal and clone the repository by running:
```
git clone https://github.com/BKristandra/Cruise_Control.git
```

This will create a local copy of the project on your machine.

### Building

Build from your teminal using CMake:

```shell
mkdir build
cd build
cmake ..
make
```

### Running

Run from your terminal using `./cruise_control`.

The code will output a timeseries velocity vector 

### Edit Local Variables
The values used in this project are the same values used in this [resource](https://ctms.engin.umich.edu/CTMS/index.php?example=CruiseControl&section=SimulinkControl), these are the variables to change for your project.

* `m = 1000 kg`: mass of the vehicle
* `b = 50 N*sec/m`: The resistance coefficient that estimates the rolling and aerodynamic resistance
* `T = 10 s`: The simulation time [ User Input ]
* `N = 20 steps`: Total number of simulation steps [ User Input ]
* `K_p = 800`: The proportional gain of the PI controller
* `K_i = 40`: the integral gain of the PI controller

## Support
If you have any inquiries, please don't hesitate to contact:

Brian: `ge35yez@tum.de`

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
This work is supervised and advised by the Technical University of Munich. 


