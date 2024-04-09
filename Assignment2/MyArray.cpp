// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
#include "Array.h"
using namespace std;

int main()
{
    // programmer's identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // Initializations 
    Array indexInput;       // represents the index array for user to input
    Array indexFlag;        // represents if the array has a value or no value
    int input;              // user input
    char value[100];        // store value from user input
    char buf[100];          // store index number from user input
    int count = 0;          // represents the number of user inputs
    cout << endl;

    // Prompts user to enter an index and value in an array
    while (true)
    {
        cout << "Input an index and a value [Q to quit]: ";
        cin >> buf;
        if (buf[0] == 'q' || buf[0] == 'Q')     // if user wish to exit 
            break;
        cin >> value;
        input = atoi(buf);                      // converts character string to integer
        if (input >= 0 && input < 100)
        {
            indexInput[input] = atoi(value);    // setter: set value to index in array
            indexFlag[input] = 1;               // setter: set index count to 1
        }
    }

    // Counting the amount of filled index
    for (int i = 0; i < 100; i++)
    {
        if (indexFlag[i] == 1)
            count += 1;
    }

    // Output in console
    cout << endl;
    cout << "You have stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl << endl;
    for (int i = 0; i < 100; i++)
    {
        if (indexFlag[i] != 0)
            cout << "\t" << i << " => " << indexInput[i] << endl;       // getter
    }
    cout << endl;

    // Prompts user to enter an index to search the value
    while (true)
    {
        cout << "Input an index for me to look up [Q to quit]: ";
        cin >> buf;
        if (buf[0] == 'q' || buf[0] == 'Q')
            break;
        input = atoi(buf);
        if (indexFlag[input] != 0)
            cout << "Found it -- the value stored at " << input << " is " << indexInput[input] << endl;
        else
            cout << "I didn't find it" << endl;
    }

    return 0;
}