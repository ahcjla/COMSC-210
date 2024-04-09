// Programmer's name: Aurelia Kisanaga
// Programmer's ID: 1960007

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // for cout, ios, and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock( ), clock_t, time, and CLOCKS_PER_SEC
#include <fstream>  // for file input and output 
#include <cstring> // for strcpy and strtok

int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    // programmer customizations go here
    int n = 8000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
    string bigOh = "O(n)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

    // for parsing the inputfile
    ifstream fin;
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;
    for (int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
        // start the timer, do something, and stop the timer
        clock_t startTime = clock();
        fin.open("dvc-schedule.txt");
        if (!fin.good())
            cout << "I/O error. File can't find!\n";

        // initialization
        int count = 0;

        while (fin.good() && count < n)
        {
            // read the line
            string line;
            getline(fin, line);
            strcpy(buf, line.c_str());

            if (buf[0] == 0) continue; // skip blank lines

            //parse the line
            const string term(token = strtok(buf, tab));
            const string section((token = strtok(0, tab)) ? token : "");
            const string course((token = strtok(0, tab)) ? token : "");
            const string instructor((token = strtok(0, tab)) ? token : "");
            const string whenWhere((token = strtok(0, tab)) ? token : "");
            if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
            const string subjectCode(course.begin(), course.begin() + course.find('-'));
            count++;
        }
        fin.close();
        clock_t endTime = clock();

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
}