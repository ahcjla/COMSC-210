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

#include "MyDynamicArray.h"


int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    // programmer customizations go here
    int n = 800; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
    string bigOh = "O(n squared)"; // YOUR PREDICTION: O(n), O(n log n), or O(n squared)

    // set output decimal precision + initialize timing variables
    cout.setf(ios::fixed);
    cout.precision(4);
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;

    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";
    ifstream fin;

    for (int cycle = 0; cycle < 4; cycle++, n *= 2)
    {
        // problem setup goes here -- create a data structure of size n
        DynamicArray<string> term(n);
        DynamicArray<string> section(n);
        DynamicArray<string> course(n);
        DynamicArray<string> instructor(n);
        DynamicArray<string> timeLocation(n);
        DynamicArray<string> subjectCode(n);
        DynamicArray<bool> codeFound(n);

        // assert that n is the size of the data structure if applicable
        assert(term.capacity() == n);
        assert(section.capacity() == n);
        assert(course.capacity() == n);
        assert(instructor.capacity() == n);
        assert(timeLocation.capacity() == n);
        assert(subjectCode.capacity() == n);
        assert(codeFound.capacity() == n);


        // start the timer, do something, and stop the timer
        clock_t startTime = clock();

        // open the input file
        fin.open("dvc-schedule.txt");
        if (!fin.good())
            cout << "I/O error. File can't be found!" << endl;

        // initialization
        int count = 0;
        int duplicates = 0;

        while (fin.good() && count < n)
        {
            // read the line
            string line;
            getline(fin, line);
            strcpy(buf, line.c_str());

            if (buf[0] == 0) continue; // skip blank lines

            // parse the line
            const string terms(token = strtok(buf, tab));
            const string sections((token = strtok(0, tab)) ? token : "");
            const string courses((token = strtok(0, tab)) ? token : "");
            const string instructors((token = strtok(0, tab)) ? token : "");
            const string whenWhere((token = strtok(0, tab)) ? token : "");
            if (courses.find('-') == string::npos) continue; // invalid line: no dash in course name
            const string subjectCodes(courses.begin(), courses.begin() + courses.find('-'));

            // assign classified data from file to dynamic array
            term[count] = terms;
            section[count] = sections;
            course[count] = courses;
            instructor[count] = instructors;
            timeLocation[count] = whenWhere;
            subjectCode[count] = subjectCodes;

            // Check duplicates
            for (int i = 0; i < count; i++)
            {
                if (term[i] == term[count] && section[i] == section[count])
                {
                    codeFound[count] = false;
                    duplicates++;
                    break;
                }
                else
                {
                    codeFound[count] = true; 
                }
            }
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

