// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
using namespace std;

#include "SortableArray.h"

int main()
{
    // Programmer's Identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // SortableArray declaration
    SortableArray<double> indexInput;
    SortableArray<bool> indexFlag;

    // Variables initialization 
    string buf;
    int index = 0;
    int maxIndex = 0;
    double userInput = 0;
    int count = 0;

    cout << endl;

    // Prompt for user input
    while (true)
    {
        cout << "Input an index and a value separated by a space [Enter Q or q to quit]: ";
        cin >> buf;
        if (buf[0] == 'Q' || buf[0] == 'q')
            break;
        index = atoi(buf.c_str());
        cin >> buf;
        if (buf[0] == 'q' || buf[0] == 'Q')
            break;
        userInput = atof(buf.c_str());
        if (maxIndex < index)
            maxIndex = index;
        if (index > -1)
        {
            indexInput[index] = userInput;
            indexFlag[index] = true;
            count++;
        }
    }
    maxIndex++;

    // Console output on the count of values 
    cout << "\nYou stored this many values: " << count << endl;
    cout << "The index-value pairs are: " << endl << "\t";
    for (int i = 0; i < maxIndex; i++)
    {
        if (indexFlag[i])
            cout << i << "=>" << indexInput[i] << ' ';
    }

    // Prompt 3: Enter how many values to sort
    int sortIndex = 0;
    cout << "\n\nEnter how many values to sort?: ";
    cin >> sortIndex;
    indexInput.sort(sortIndex);
    cout << "\t";
    for (int i = 0; i < maxIndex; i++)
    {
        if (indexFlag[i])
            cout << i << "=>" << indexInput[i] << ' ';
    }
    cout << endl << endl;

    // Search data 
    while (true)
    {
        cout << "Input an index for me to look up [Enter Q or q to quit]: ";
        cin >> buf;
        if (buf[0] == 'Q' || buf[0] == 'q')
            break;
        index = atoi(buf.c_str());
        if (!indexFlag[index])
        {
            cout << "Not found -- there is no value stored at index " << index << endl;
        }
        else
        {
            cout << "Found it -- the value stored at " << index << " is " << indexInput[index] << endl;
        }
        cout << endl;
    }
}