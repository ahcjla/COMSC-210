// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <string>
#include <cassert>
#include "StaticArray.h"
#include "StaticArray.h" // ifndef test

using namespace std;


int main2()
{
    // Programmer's identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // TEST FOR INTEGERS (int)
    cout << "\nTEST FOR INT STATIC ARRAY\n";

    StaticArray<int, 100> a;

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0);

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
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

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<int, 100> b = a;
    for (int i = 0; i < 100; i++)
        assert(a[i] == b[i]);

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<int, 100> c; // if this compiles, Array::Array main constructor exists 
    assert(c.capacity() == 100); // if this compiles, Array::capacity is a getter 
    assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter 
    assert(c[-1] == c[-1]); // tests the getter's range checking 


    // TEST FOR DOUBLE (double)
    cout << "\nTEST FOR DOUBLE STATIC ARRAY\n";

    StaticArray<double, 100> x;

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << x.capacity() << endl;
    assert(100 == x.capacity());

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < x.capacity(); i++)
        assert(x[i] == 0.0);

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    x[6] = 12356.7;
    x[7] = 76543.21;
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: 12356.7 for x[6]\n";
    cout << "ACTUAL: " << x[6] << endl;
    assert(12356.7 == x[6]);
    cout << "EXPECTED: 76543.21 for x[7]\n";
    cout << "ACTUAL: " << x[7] << endl;
    assert(76543.21 == x[7]);
    x[-1000] = 123123;
    cout << "EXPECTED: 123123 for x[-1000]\n";
    cout << "ACTUAL: " << x[-1000] << endl;
    assert(12356.7 == x[6]);
    assert(76543.21 == x[7]);
    assert(123123 == x[-6]); // any out-of-range uses dummy
    assert(123123 == x[10]); // checks upper end of range
    assert(123123 != x[9]); // checks upper end of range
    assert(123123 != x[0]); // checks lower end of range

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<double, 100> y = x;
    for (int i = 0; i < 100; i++)
        assert(x[i] == y[i]);

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<double, 100> z; // if this compiles, Array::Array main constructor exists 
    assert(z.capacity() == 100); // if this compiles, Array::capacity is a getter 
    assert(z[0] == z[0]); // if this compiles, there is an Array::operator[ ] getter 
    assert(z[-1] == z[-1]); // tests the getter's range checking 


    // TEST FOR CHARACTERS (char)
    cout << "\nTEST FOR CHAR STATIC ARRAY\n";

    StaticArray<char, 100> m;

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << m.capacity() << endl;
    assert(100 == m.capacity());

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < m.capacity(); i++)
        assert(m[i] == '\0');

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    m[6] = 'a';
    m[7] = 'b';
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: a for m[6]\n";
    cout << "ACTUAL: " << m[6] << endl;
    assert('a' == m[6]);
    cout << "EXPECTED: b for m[7]\n";
    cout << "ACTUAL: " << m[7] << endl;
    assert('b' == m[7]);
    m[-1000] = 'c';
    cout << "EXPECTED: c for m[-1000]\n";
    cout << "ACTUAL: " << m[-1000] << endl;
    assert('a' == m[6]);
    assert('b' == m[7]);
    assert('c' == m[-6]); // any out-of-range uses dummy
    assert('c' == m[10]); // checks upper end of range
    assert('c' != m[9]); // checks upper end of range
    assert('c' != m[0]); // checks lower end of range

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<char, 100> n = m;
    for (int i = 0; i < 100; i++)
        assert(m[i] == n[i]);

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<char, 100> o; // if this compiles, Array::Array main constructor exists 
    assert(o.capacity() == 100); // if this compiles, Array::capacity is a getter 
    assert(o[0] == o[0]); // if this compiles, there is an Array::operator[ ] getter 
    assert(o[-1] == o[-1]); // tests the getter's range checking 


    // TEST FOR STRINGS (string)
    cout << "\nTEST FOR STRING STATIC ARRAY\n";

    StaticArray<string, 100> s;

    // StaticArray::capacity
    cout << "\nTesting StaticArray::capacity\n";
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << s.capacity() << endl;
    assert(100 == s.capacity());

    // StaticArray::StaticArray
    cout << "\nTesting StaticArray::StaticArray\n";
    for (int i = 0; i < s.capacity(); i++)
        assert(s[i] == "\0");

    // StaticArray::operator[ ] setter
    cout << "\nTesting the StaticArray::operator[ ] setter\n";
    s[6] = "abc";
    s[7] = "def";
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: abc for s[6]\n";
    cout << "ACTUAL: " << s[6] << endl;
    assert("abc" == s[6]);
    cout << "EXPECTED: def for s[7]\n";
    cout << "ACTUAL: " << s[7] << endl;
    assert("def" == s[7]);
    s[-1000] = "ghi";
    cout << "EXPECTED: c for s[-1000]\n";
    cout << "ACTUAL: " << s[-1000] << endl;
    assert("abc" == s[6]);
    assert("def" == s[7]);
    assert("ghi" == s[-6]); // any out-of-range uses dummy
    assert("ghi" == s[10]); // checks upper end of range
    assert("ghi" != s[9]); // checks upper end of range
    assert("ghi" != s[0]); // checks lower end of range

    // StaticArray::operator[ ] getter
    cout << "\nTesting the StaticArray::operator[ ] getter\n";
    const StaticArray<string, 100> t = s;
    for (int i = 0; i < 100; i++)
        assert(s[i] == t[i]);

    // const object test
    cout << "\nConst object test\n";
    const StaticArray<char, 100> u; // if this compiles, Array::Array main constructor exists 
    assert(u.capacity() == 100); // if this compiles, Array::capacity is a getter 
    assert(u[0] == u[0]); // if this compiles, there is an Array::operator[ ] getter 
    assert(u[-1] == u[-1]); // tests the getter's range checking 

    return 0;
}
