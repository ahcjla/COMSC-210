// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
#include <string>
#include "StaticArray.h"
using namespace std;

int main()
{
    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // StaticArray declaration
    StaticArray<double, 100> indexInput;
    StaticArray<bool, 100> indexFlag;

    // Variables initialization 
    char buf[100];
    double userInput;
    int count = 0;
    
    cout << endl;

    // Prompt for user input
    while (true)
    {
        cout << "Input an index and a value [Q to quit]: ";
        cin >> buf;
        if (buf[0] == 'Q' || buf[0] == 'q')
            break;
        cin >> userInput;
        int index = atoi(buf);
        indexInput[index] = userInput;
        indexFlag[index] = true;
    }

    // Counting the amount of filled index
    for (int i = 0; i < indexFlag.capacity(); i++)
    {
        if (indexFlag[i])
            count += 1;
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
        userInput = atoi(buf);
        if (indexFlag[userInput])
            cout << "Found it -- the value stored at " << userInput << " is " << indexInput[userInput] << endl;
        else
            cout << "I didn't find it" << endl;
    }

    return 0;
}

