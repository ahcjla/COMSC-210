// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cstdlib>
#include "Array.h"
using namespace std;

Array::Array()
{
    for (int i = 0; i < 100; i++)
        values[i] = int();
};

int Array::capacity() const {return 100;}

int& Array::operator[ ](int index)
{
    if (index < 0) return dummy;
    if (index >= 100) return dummy;
    return values[index];
}

int Array::operator[ ](int index) const
{
    if (index < 0) return 0;
    if (index >= 100) return 0;
    return values[index];
}