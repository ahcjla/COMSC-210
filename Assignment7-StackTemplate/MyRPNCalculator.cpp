// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
#include "Stack.h"
using namespace std;

// Prototype
void printOutput(Stack<double>);

int main()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    // Initialization
    double value, secondNum, firstNum, result;
    string buf;
    Stack<double> RPNcalc;

    cout << "Enter: ";
    cin >> buf;
    while (true)
    {
        if (buf[0] == 'q' || buf[0] == 'Q') break;
        if (RPNcalc.empty() && RPNcalc.size() < 2)
        {
            if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
            {
                buf[0] = ' ';
            }
            else
            {
                value = atof(buf.c_str());
                RPNcalc.push(value);
            }
        }
        else if (buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')
        {
            secondNum = RPNcalc.peek();
            RPNcalc.pop();
            firstNum = RPNcalc.peek();
            RPNcalc.pop();
            if (buf[0] == '+')
            {
                result = firstNum + secondNum;
                RPNcalc.push(result);
            }
            else if (buf[0] == '-')
            {
                result = firstNum - secondNum;
                RPNcalc.push(result);
            }
            else if (buf[0] == '*')
            {
                result = firstNum * secondNum;
                RPNcalc.push(result);
            }
            else if (buf[0] == '/')
            {
                result = firstNum / secondNum;
                RPNcalc.push(result);
            }
            else
            {
                value = atof(buf.c_str());
                RPNcalc.push(value);
            }
        }
        else
        {
            value = atof(buf.c_str());
            RPNcalc.push(value);
        }
        cout << "Enter: ";
        printOutput(RPNcalc);
        cin >> buf;
    }
    return 0;
}

// Function to print the ouput of the stack in reverse 
void printOutput(Stack<double> calc) 
{
    Stack<double> copy = calc;
    int size = copy.size();
    for (int i = 0; i < size; i++)
    {
        cout << copy.peek() << " ";
        copy.pop();
    }
}