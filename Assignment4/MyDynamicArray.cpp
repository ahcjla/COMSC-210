// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
#include <string>
#include "DynamicArray.h"
using namespace std;

int main()
{
    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // DynamicArray declaration
    DynamicArray<double> indexInput;
    DynamicArray<bool> indexFlag;

    // Variables initialization 
    string buf;
    int index = 0;
    double userInput = 0;
    int count = 0;

    cout << endl;

    // Prompt for user input
    while (true)
    {
        cout << "Input an index and a value [Q to quit]: ";
        cin >> buf;
        if (buf[0] == 'Q' || buf[0] == 'q')
            break;
        index = atoi(buf.c_str());
        cin >> buf;
        if (buf[0] == 'q' || buf[0] == 'Q') 
            break;
        userInput = atof(buf.c_str());
        indexInput[index] = userInput;
        indexFlag[index] = true;
    }


    // Counting the amount of filled index
    for (int i = 0; i < indexFlag.capacity(); i++)
    {
        if (indexFlag[i])
            count++;
    }

    // Console output on the count of values 
    cout << "\nYou stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl << endl;
    for (int i = 0; i < indexFlag.capacity(); i++)
    {
        if (indexFlag[i])
            cout << "\t" << i << " => " << indexInput[i] << endl;
    }

    cout << endl;

    // Search data 
    while (true)
    {
        cout << "Input an index for me to look up [Q to quit]: ";
        cin >> buf;
        if (buf[0] == 'Q' || buf[0] == 'q')
            break;
        index = atoi(buf.c_str());
        if (indexFlag[index] && index > -1)
            cout << "Found it -- the value stored at " << index << " is " << indexInput[index] << endl;
        else
            cout << "Sorry, but there is no value stored at index " << index << endl;
    }


    return 0;
}