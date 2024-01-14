# Airport Simulation

## Overview

This C++ program simulates the arrival and service of airplanes at an airport, keeping track of the wait times for each airplane in the landing queue. The simulation runs for a specified maximum time (`Tmax`) in minutes.

## Program Output

The program produces output detailing the arrivals, service initiation times, and wait times for each airplane. Additionally, it calculates and outputs the average wait time for all serviced airplanes.

## Program Structure

The program is structured as follows:

- **DEQ.h**: Header file for the Double-Ended Queue (DEQ) data structure used in the simulation.

- **main.cpp**: The main source file containing the implementation of the airport simulation. It includes functions for generating random integers, processing arrivals, removing jobs from the queue, processing service, and calculating the average wait time.

## How to Run

Compile and run the program using a C++ compiler. Ensure that the DEQ.h file is in the same directory as the main.cpp file. The program outputs details of arrivals, service initiation times, and the average wait time.

```bash
$ g++ main.cpp -o airport_simulation
$ ./airport_simulation
```

Dependencies

The program uses the C++ standard library and the Double-Ended Queue (DEQ) data structure defined in the DEQ.h header file.

Configuration

Tmax: Maximum simulation time in minutes.
Tr: Remaining service time for the current job.
Random Number Generation

The program uses the randInt function to generate random integers within a specified range.

Sample Output
Arrival #1 at: 2
Job #1 Service Started at: 2 Wait = 0
Arrival #2 at: 10
...
Average Wait Time is 88.5161

Author

Farida Ragheb (ID: 900225892)
Mohamed El-Refai (ID: 900222334)
