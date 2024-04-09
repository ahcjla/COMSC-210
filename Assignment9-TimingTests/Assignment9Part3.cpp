// Programmer's name: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream> // for cout, ios, and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock( ), clock_t, time, and CLOCKS_PER_SEC

// your H file #include(s) go here, plus any more library includes
#include "MyDynamicArray.h"

int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    srand(time(0)); 
    rand(); // seed the random number generator (in case you need it)

    // programmer customizations go here
    int n = 1000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
    string bigOh = "O(n squared)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;
    for (int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
        // problem setup goes here -- create a data structure of size n
        DynamicArray<int> random(n);
        for (int i = 0; i < n; i++) 
            random[i] = rand();

        // assert that n is the size of the data structure if applicable
        assert(random.capacity() == n);

        // start the timer, do something, and stop the timer
        clock_t startTime = clock();
        // do something where n is the "size" of the problem
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (random[j] < random[i])
                    swap(random[i], random[j]); // required algorithm C++ library
        clock_t endTime = clock();

        // validation block -- assure that process worked if applicable
        for (int i = 1; i < n; i++)
            assert(random[i - 1] <= random[i]);

        // compute timing results
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        else if (bigOh == "O(n)")
            expectedSeconds = factor * elapsedSecondsNorm;
        else if (bigOh == "O(n log n)")
            expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        else if (bigOh == "O(n squared)")
            expectedSeconds = factor * factor * elapsedSecondsNorm;

        // reporting block
        cout << elapsedSeconds;
        if (cycle == 0) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedSeconds << ')';
        cout << " for n=" << n << endl;
    }
    return 0;
}