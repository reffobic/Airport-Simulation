//
//  main.cpp
//  Project
//
//  Created by Farida Ragheb 900225892 and Mohamed El-Refai 900222334.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DEQ.h"
using namespace std;

// Function to generate random integers between a range
int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to process arrivals
void Arrival(DEQ<int>& Q, int t, int deltaT, int& ArrivalCount)
{
    double Pa = 1.0 / deltaT;
    double R = static_cast<double>(rand()) / RAND_MAX;
    if (R < Pa)
    {
        if (Q.DEQisFull())
        {
            cout << "Error: Line is full" << endl; // Line is full, unable to add arrival
        }
        else
        {
            int Tarrival = t; // Arrival time of the job
            Q.AddRear(Tarrival); // Add the arrival time to the queue
            cout << "Arrival #" << ArrivalCount+1 << " at: " << Tarrival << endl; // Output arrival information
        }
        ArrivalCount++;
    }
}

// Function to remove job from the line
void ExitLine(DEQ<int>& Q, int t, int& waitTotal, int& JobCount)
{
    if (Q.DEQisEmpty())
    {
        cout << "Report: Line is Empty" << endl; // Line is empty, unable to remove job
    }
    else
    {
        int Tarrival = Q.ViewFront(); // Arrival time of the job at the front of the queue
        int Tw = t - Tarrival; // Wait time for the serviced job
        waitTotal += Tw; // Accumulate the total wait time
        cout << "Job #" << JobCount+1 << " Service Started at: " << t << " Wait = " << Tw << endl; // Output service information
        Q.RemoveFront(); // Remove the serviced job from the queue
        JobCount++;
    }
}

// Function to process service
void Service(DEQ<int>& Q, int t, int& Tr, int& waitTotal, int& jobCount)
{
    if (Tr == 0 && !Q.DEQisEmpty())
    {
        int Tlanding = 10; // Service time required for landing (in minutes)
        ExitLine(Q, t, waitTotal, jobCount); // Process job removal from the line
        Tr = Tlanding; // Set the remaining service time for the current job
    }
}

// Function to calculate average wait time
double AverageWait(int waitTotal, int jobCount)
{
    if (jobCount == 0)
    {
        return 0; // No jobs, average wait time is 0
    }
    else
    {
        return static_cast<double>(waitTotal) / jobCount; // Calculate and return the average wait time
    }
}

int main()
{
    srand(static_cast<unsigned>(time(NULL))); // Initialize random number generator
    
    int Tmax = 360; // Maximum simulation time (in minutes)
    int jobCount = 0; // Count of jobs serviced
    int ArrivalCount = 0; // Count of jobs arrived
    int waitTotal = 0; // Total wait time in the landing queue
    int t = 0; // Clock time
    int Tr = 0; // Remaining service time for the current job
    
    DEQ<int> landingqueue; // Queue to hold arrival times of jobs

    while (t < Tmax)
    {
        Arrival(landingqueue, t, 6, ArrivalCount); // Process arrivals

        if (Tr == 0 && !landingqueue.DEQisEmpty())
        {
            int Tlanding = 10; // Service time required for landing (in minutes)
            int Tarrival = landingqueue.ViewFront(); // Arrival time of the job at the front of the queue
            int Tw = t - Tarrival; // Wait time for the serviced job
            waitTotal += Tw; // Accumulate the total wait time
            cout << "Job #" << jobCount+1 << " Service Started at: " << t << " Wait = " << Tw << endl; // Output service information
            landingqueue.RemoveFront(); // Remove the serviced job from the queue
            jobCount++;
            Tr = Tlanding; // Set the remaining service time for the current job
        }

        if (Tr > 0)
        {
            Tr--; // Decrement remaining service time
        }

        t++; // Increment the clock time
    }

    while (!landingqueue.DEQisEmpty())
    {
        int Tarrival = landingqueue.ViewFront();
        int Tw = t - Tarrival;
        waitTotal += Tw;
        cout << "Job #" << jobCount+1 << " Service Started at: " << t << " Wait = " << Tw << endl;
        landingqueue.RemoveFront();
        jobCount++;
    }

    double averageWait = AverageWait(waitTotal, jobCount); // Calculate average wait time

    cout << "Average Wait Time is " << averageWait << endl; // Output average wait time

    return 0;
}


