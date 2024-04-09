// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#ifndef ARRAY_H
#define ARRAY_H
using namespace std;

class Array
{
    int values[100];
    int dummy;

    public:
    Array(); // constructor
    int capacity() const;
    int operator[ ](int) const; // getter version
    int& operator[](int); // setter version
};


#endif
