// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cassert>
#include "Array.h"
#include <cstdlib>
using namespace std;


int main2() 
{
    // Programmer's identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    Array a;

    // Array::capacity
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());

    // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0);

    // Array::operator[ ] setter
    cout << "\nTesting the Array::operator[ ] setter\n";
    a[6] = 12356;
    a[7] = 7654321;
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for a[6]\n";
    cout << "ACTUAL: " << a[6] << endl;
    assert(12356 == a[6]);
    cout << "EXPECTED: 7654321 for a[7]\n";
    cout << "ACTUAL: " << a[7] << endl;
    assert(7654321 == a[7]);
    a[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << a[-1000] << endl;
    assert(12356 == a[6]);
    assert(7654321 == a[7]);
    assert(123123 == a[-6]); // any out-of-range uses dummy
    assert(123123 == a[10]); // checks upper end of range
    assert(123123 != a[9]); // checks upper end of range
    assert(123123 != a[0]); // checks lower end of range

    // Array::operator[ ] getter
    cout << "\nTesting the Array::operator[ ] getter\n";
    const Array b = a;
    for (int i = 0; i < 100; i++)
        assert(a[i] == b[i]);

    // const object test
    cout << "\nConst object test\n";
    const Array c; // if this compiles, Array::Array main constructor exists 
    assert(c.capacity() == 100); // if this compiles, Array::capacity is a getter 
    assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter 
    assert(c[-1] == c[-1]); // tests the getter's range checking 

    return 0;
}




