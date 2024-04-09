// Programmer: Aurelia Kisanaga 
// Programmer's ID: 1960007

#include <ctime>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <string> // for string
#include <cmath> // for log and pow
using namespace std;

#include "PriorityQueue.h"

int main() 
{

    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    srand(time(0)); 
    rand();

    int n = 1000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
    const int reps = n / 100;

    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0.0;

    for (int cycle = 0; cycle < 4; cycle++, n *= 2) 
    {
        PriorityQueue<int> test(n * 2);
        for (int i = 0; i < n; i++) 
        {
            test.push(i);
        }

        assert(test.size() == n);



        //Start Time
        clock_t startTime = clock();

        for (int rep = 0; rep < reps; rep++) 
        {
            test.push(rand() % n);
        }

        //End Time
        clock_t endTime = clock();

        // Hi-to-lo
        PriorityQueue<int> test2 = test;
        while (!test2.empty())
        {
            int temp = test2.top();
            test2.pop();
            assert(temp >= test2.top());
        }

        // compute timing results
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0) elapsedSecondsNorm = elapsedSeconds;
        double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

        // reporting block
        cout << elapsedSeconds;
        if (cycle == 0) cout << " (expected)";
        else cout << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ')';
        cout << " for n=" << n << endl;


    }

}