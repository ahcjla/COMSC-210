// Programmer's Name: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

// Prototype
int getRandomNumberOfArrivals(double);

struct Customer
{
    char IDtag;
    int arrivalTime;
    int endTime;
};

int main()
{
    srand(time(0)); 
    rand();

    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    // Initializations
    int totalNumSer = 0;
    float rate = 0.00;
    int maxQ = 0;
    int minSerTime = 0;
    int maxSerTime = 0;
    int endMinute = 0;

    // ID tag
    char first = 'A';
    char last = 'Z';
    int count = 0;

    // Obtain input from file
    ifstream fin;
    fin.open("simulation.txt");
    if (!fin.good())
        cout << "I/O error. File can't find!\n";
    string line;
    getline(fin, line);
    totalNumSer = stoi(line);
    getline(fin, line);
    rate = stof(line);
    getline(fin, line);
    maxQ = stoi(line);
    getline(fin, line);
    minSerTime = stoi(line);
    getline(fin, line);
    maxSerTime = stoi(line);
    getline(fin, line);
    endMinute = stoi(line);

    fin.close();
    
    // Output data
    cout << "Number of Servers: " << totalNumSer << endl;
    cout << "Customer Arrival Rate: " << rate << " per minute, for " << endMinute << " minutes" << endl;
    cout << "Maximum Queue Length: " << maxQ << endl;
    cout << "Minimum Service Time: " << minSerTime << " minutes" << endl;
    cout << "Maximum Service Time: " << maxSerTime << " minutes" << endl;
    cout << endl;

    // intercval service time for later use
    int serviceTimeInterval = maxSerTime - minSerTime;

    // Object initialization 
    Queue<Customer> waitingLine;
    DynamicArray<Customer> nowServing;
    DynamicArray<bool> serverBusy;

    // increment time every minute each time enter is pressed
    for (int time = 0;; time++)
    {
        for (int i = 0; i < totalNumSer; i++)       // loop through each server
        {
            if (serverBusy[i] == true)              // if server is busy then check end time of service
            {
                if (nowServing[i].endTime == time)  // if end time service is equals to current minute
                {
                    serverBusy[i] = false;          // set server to available 
                }
            }
        }
        if (time < endMinute)           // if time is less than the expected end time of service
        {
            int numOfArrival = getRandomNumberOfArrivals(rate);   // get number of arrivals 
            for (int j = 0; j < numOfArrival; j++)      // for each person of num of arrivals
            {
                if (waitingLine.size() < maxQ)      // if queue is less than maximum queue
                {   // create new object and set arrival time and ID tag
                    Customer newCustomer;
                    newCustomer.arrivalTime = time;
                    if (first + count > last)
                    {
                        newCustomer.IDtag = first;
                        count = 0;
                    }
                    else
                    {
                        newCustomer.IDtag = first + count;
                    }
                    waitingLine.push(newCustomer);  // push new object to back of queue
                    count++;
                }
            }   
        }
        for (int k = 0; k < totalNumSer; k++)
        {   // if server is not busy and there is someone in the queue,...
            if (serverBusy[k] == false && !waitingLine.empty())
            {   //... set server to be busy and move most front customer to be in the now serving array
                Customer front = waitingLine.front();
                waitingLine.pop();
                nowServing[k] = front;
                // create random number for the end time service of customer 
                nowServing[k].endTime = time + (rand() % (serviceTimeInterval + 1) + minSerTime);
                serverBusy[k] = true;
            }
        }

        // Output visualization of queue table
        cout << "Time: " << time << endl;
        cout << "-----------------------------------" << endl;
        cout << left << setw(10) << "Server" << setw(15) << "Now Serving" << "Wait Queue" << endl;
        cout << left << setw(10) << "------" << setw(15) << "-----------" << "----------" << endl;
        for (int x = 0; x < totalNumSer; x++)
        {
            cout << right << setw(3) << x;      // output server index
            if (serverBusy[x] == false)
            {
                if (x == 0)
                {
                    Queue<Customer> copyLine = waitingLine;
                    cout << setw(9) << " ";
                    for (int y = 0; y < waitingLine.size(); y++)
                    {
                        cout << copyLine.front().IDtag;         // output waiting line
                        copyLine.pop();                         // remove most front customer
                    }
                }
                cout << endl;
            }
            else
            {
                cout << setw(13) << nowServing[x].IDtag;    // output the ID tag of customer
                if (x == 0)
                {
                    Queue<Customer> copyLine = waitingLine;
                    cout << setw(9) << " ";
                    for (int y = 0; y < waitingLine.size(); y++)
                    {
                        cout << copyLine.front().IDtag;     // output waiting line
                        copyLine.pop();                     // remove most front customer
                    }
                }
                cout << endl;
            }
        }
        cout << "-----------------------------------" << endl;

        // check if simulation has ended. 
        bool done = false;
        // check for each server,...
        for (int z = 0; z < totalNumSer; z++)
        {   //... if waiting line is empty, time is more than closing time, and server is not busy
            if (waitingLine.size() == 0 && time >= endMinute && serverBusy[z] == false)
            {
                done = true;    // then simulation end
            }
            else
            {
                break;          // else go through the above loop again
            }
        }

        // output and announce that simulation has ended
        if (done == true)
        {
            cout << "\nDone!\n";
            break;
        }

        cout << "Press ENTER to continue...\n";
        cin.get();

    }
    return 0;
}

// Poisson Dist
int getRandomNumberOfArrivals(double averageArrivalRate)
{
    int arrivals = 0;
    double probOfnArrivals = exp(-averageArrivalRate);
    for (double randomValue = (double)rand() / RAND_MAX;
        (randomValue -= probOfnArrivals) > 0.0;
        probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
    return arrivals;
}