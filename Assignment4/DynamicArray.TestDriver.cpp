// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h"   // ifndef test

using namespace std;

int main2()
{
    // Programmer's identification
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << endl;

    // TEST FOR INTEGERS (int)
    cout << "\nTEST FOR INT DYNAMIC ARRAY\n";

    DynamicArray<int> i;
    i.capacity(25);

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 25\n";
    cout << "ACTUAL: " << i.capacity() << endl;

    // DynamicArray::capacity (int)
    cout << "\nTesting Setter Capacity DynamicArray::capacity setter\n";
    i[0] = 5;
    i[12] = 27;
    i[24] = 72;
    i[25] = 55;
    i[52] = 77;
    cout << "i[0]: Expected: 5\n";
    cout << "Actual: " << i[0] << "\n";
    assert(5 == i[0]);
    cout << "i[12]: Expected: 27\n";
    cout << "Actual: " << i[12] << "\n";
    assert(27 == i[12]);
    cout << "i[24]: Expected: 72\n";
    cout << "Actual: " << i[24] << "\n";
    assert(72 == i[24]);
    cout << "i[25]: Expected 55\n";
    cout << "Actual: " << i[25] << "\n";
    assert(55 == i[25]);
    cout << "i[52]: Expected 77\n";
    cout << "Actual: " << i[52] << "\n";
    assert(77 == i[52]);

    // DynamicArray::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    i[6] = 12356;
    i[7] = 7654321;
    cout << "\nTesting Array::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for i[6]\n";
    cout << "ACTUAL: " << i[6] << endl;
    assert(12356 == i[6]);
    cout << "EXPECTED: 7654321 for i[7]\n";
    cout << "ACTUAL: " << i[7] << endl;
    assert(7654321 == i[7]);
    i[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << i[-1000] << endl;
    assert(12356 == i[6]);
    assert(7654321 == i[7]);
    assert(123123 == i[-25]); // any out-of-range uses dummy
    assert(123123 == i[-555]); // any out-of-range uses dummy
    assert(123123 == i[-6]); // any out-of-range uses dummy
    assert(123123 != i[0]); // checks lower end of range

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<int> b = i;
    for (int j = 0; j < 100; j++)
        assert(b[j] == i[j]);

    // Object copy test
    cout << "\nObject copy test\n";
    DynamicArray<int> o = i; // making a copy
    assert(i.capacity() == o.capacity());
    for (int j = 0; j < i.capacity(); j++)
        assert(i[j] == o[j]); // uses the setter version for both i and j
    // change the content in the original array to verify it's not a shallow copy
    for (int j = 0; j < i.capacity(); j++)
    {
        i[j]++;
        assert(i[j] != o[j]);
    }

    // Object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<int> p; p = i;
    assert(i.capacity() == p.capacity());
    for (int j = 0; j < i.capacity(); j++)
        assert(i[j] == p[j]);
    // change the content in the original array to verify it's not a shallow copy
    for (int j = 0; j < i.capacity(); j++)
    {
        i[j]++;
        assert(i[j] != p[j]);
    }

    // Const Object Test
    cout << "\nConst Object Test\n";
    assert(i.capacity());//if this compiles, capacity() is a getter
    assert(b[0] == b[0]);//if this compiles, there is a getter
    assert(b[-1] == b[-1]);//tests the getter's range


    // TEST FOR DOUBLE (double)
    cout << "\nTEST FOR DOUBLE DYNAMIC ARRAY\n";

    DynamicArray<double> d;     //d as in double
    d.capacity(25);

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED: 25\n";
    cout << "ACTUAL: " << d.capacity() << endl;

    // DynamicArray::capacity (int)
    cout << "\nTesting Setter Capacity DynamicArray::capacity setter\n";
    d[0] = 65;
    d[12] = 127;
    d[24] = 172;
    d[25] = 555.5;
    d[52] = 777.7;
    cout << "d[0]: Expected: 65\n";
    cout << "Actual: " << d[0] << "\n";
    assert(65 == d[0]);
    cout << "d[12]: Expected: 127\n";
    cout << "Actual: " << d[12] << "\n";
    assert(127 == d[12]);
    cout << "d[24]: Expected: 172\n";
    cout << "Actual: " << d[24] << "\n";
    assert(172 == d[24]);
    cout << "d[25]: Expected 555.5\n";
    cout << "Actual: " << d[25] << "\n";
    assert(555.5 == d[25]);
    cout << "d[52]: Expected 777.7\n";
    cout << "Actual: " << d[52] << "\n";
    assert(777.7 == d[52]);

    // DynamicArray::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    d[-55] = 54321.0;
    cout << "d[-55]: Expected: 54321\n";
    cout << "Actual: " << d[-55] << "\n";
    assert(d[-55] == 54321.0);
    cout << "d[-525]: Expected: 54321\n";
    cout << "Actual: " << d[-525] << "\n";
    assert(d[-525] == 54321.0);
    assert(54321.0 == d[-25]);      //Out-of-range uses dummy
    assert(54321.0 == d[-125]);     //Out-of-range uses dummy
    assert(54321.0 != d[0]);        //Checks lower end of range

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<double>y = d;
    for (int j = 0; j < d.capacity(); j++) 
        assert(d[j] == y[j]);

    // Object copy test
    cout << "\nObject Copy Test\n";
    DynamicArray<double>u = d;
    assert(d.capacity() == u.capacity());
    for (int j = 0; j < d.capacity(); j++)
        assert(d[j] == u[j]);
    for (int j = 0; j < d.capacity(); j++)
    {
        d[j]++;
        assert(d[j] != u[j]);
    }

    // Object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<double>t; t = d;
    assert(d.capacity() == t.capacity());
    for (int j = 0; j < d.capacity(); j++)
        assert(d[j] == t[j]);
    for (int j = 0; j < d.capacity(); j++) 
    {
        d[j]++;
        assert(d[j] != t[j]);
    }

    // Const Object Test
    cout << "\nConst Object Test\n";
    assert(d.capacity());//if this compiles, capacity() is a getter
    assert(y[0] == y[0]);//if this compiles, there is a getter
    assert(y[-1] == y[-1]);//tests the getter's range



    // TEST FOR CHAR (char)
    cout << "\nTEST FOR CHAR DYNAMIC ARRAY\n";

    DynamicArray<char> c;       //c as in char
    c.capacity(26);

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "Expected: 26\n";
    cout << "Actual: " << c.capacity() << "\n";

    // DynamicArray::capacity (int)
    cout << "\nTesting Setter Capacity DynamicArray::capacity setter\n";
    c[0] = 'a';
    c[12] = 'i';
    c[25] = 'z';
    c[35] = '%';
    c[55] = '*';
    cout << "c[0]: Expected: a\n";
    cout << "Actual: " << c[0] << "\n";
    assert('a' == c[0]);
    cout << "c[12]: Expected: i\n";
    cout << "Actual: " << c[12] << "\n";
    assert('i' == c[12]);
    cout << "c[25]: Expected: z\n";
    cout << "Actual: " << c[25] << "\n";
    assert('z' == c[25]);
    cout << "c[35]: Expected %\n";
    cout << "Actual: " << c[35] << "\n";
    assert('%' == c[35]);
    cout << "c[55]: Expected *\n";
    cout << "Actual: " << c[55] << "\n";
    assert('*' == c[55]);

    // DynamicArray::operator[ ] setter
    cout << "\nTesting the DynamicArray::operator[ ] setter\n";
    c[-55] = '+';
    cout << "c[-55]: Expected: +\n";
    cout << "Actual: " << c[-55] << "\n";
    assert('+' == c[-55]);
    cout << "c[-125]: Expected: +\n";
    cout << "Actual: " << c[-125] << "\n";
    assert('+' == c[-125]);
    assert('+' == c[-25]);  //Out-of-range uses dummy
    assert('+' == c[-261]); //Out-of-range uses dummy
    assert('+' != c[0]);    //Checks lower end of range

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<char>x = c;
    for (int j = 0; j < c.capacity(); j++)
        assert(c[j] == x[j]);

    // Object copy test
    cout << "\nObject Copy Test\n";
    DynamicArray<char>r = c;
    assert(r.capacity() == c.capacity());
    for (int j = 0; j < c.capacity(); j++)
        assert(r[j] == c[j]);
    for (int j = 0; j < c.capacity(); j++) 
    {
        c[j]++;
        assert(c[j] != r[j]);
    }

    // Object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<char>e; e = c;
    assert(c.capacity() == e.capacity());
    for (int j = 0; j < c.capacity(); j++)
        assert(c[j] == e[j]);
    for (int j = 0; j < c.capacity(); j++) 
    {
        c[j]++;
        assert(c[j] != e[j]);
    }

    // Const Object Test
    cout << "\nConst Object Test\n";
    assert(c.capacity());//if this compiles, capacity() is a getter
    assert(x[0] == x[0]);//if this compiles, there is a getter
    assert(x[-1] == x[-1]);//tests the getter's range



    // TEST FOR STRING (string)
    cout << "\nTEST FOR STRING DYNAMIC ARRAY\n";

    DynamicArray<string> s;     //s as in string
    s.capacity(25);

    // DynamicArray::capacity
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "Expected: 25\n";
    cout << "Actual: " << s.capacity() << "\n";

    // DynamicArray::capacity (int)
    cout << "\nTesting Setter Capacity DynamicArray::capacity setter\n";
    s[0] = "zero";
    s[12] = "twelve";
    s[24] = "twenty four";
    s[25] = "twenty five";
    s[50] = "fifty";
    cout << "s[0]: Expected: zero\n";
    cout << "Actual: " << s[0] << "\n";
    assert("zero" == s[0]);
    cout << "s[12]: Expected: twelve\n";
    cout << "Actual: " << s[12] << "\n";
    assert("twelve" == s[12]);
    cout << "s[24]: Expected: twenty four\n";
    cout << "Actual: " << s[24] << "\n";
    assert("twenty four" == s[24]);
    cout << "s[25]: Expected: twenty five\n";
    cout << "Actual: " << s[25] << "\n";
    assert("twenty five" == s[25]);
    cout << "s[50]: Expected: fifty\n";
    cout << "Actual: " << s[50] << "\n";
    assert("fifty" == s[50]);

    // DynamicArray::operator[ ] setter
    s[-55] = "dummy";
    cout << "s[-55]: Expected: dummy\n";
    cout << "Actual: " << s[-55] << "\n";
    assert(s[-55] == "dummy");
    cout << "s[-125]: Expected: dummy\n";
    cout << "Actual: " << s[-125] << "\n";
    assert(s[-125] == "dummy");
    assert("dummy" == s[-25]);//Out-of-range uses dummy
    assert("dummy" == s[-125]);//Out-of-range uses dummy
    assert("dummy" != s[0]);//Checks lower end of range

    // DynamicArray::operator[ ] getter
    cout << "\nTesting the DynamicArray::operator[ ] getter\n";
    const DynamicArray<string>w = s;
    for (int j = 0; j < s.capacity(); j++)
        assert(s[j] == w[j]);

    // Object copy test
    cout << "\nObject Copy Test\n";
    DynamicArray<string>l = s;
    assert(s.capacity() == l.capacity());
    for (int j = 0; j < s.capacity(); j++)
        assert(s[j] == l[j]);
    for (int j = 0; j < s.capacity(); j++) 
    {
        s[j] = "changed";
        assert(s[j] != l[j]);
    }

    // Object assignment test
    cout << "\nObject assignment test\n";
    DynamicArray<string>k; k = s;
    assert(s.capacity() == k.capacity());
    for (int j = 0; j < s.capacity(); j++)
        assert(s[j] == k[j]);
    for (int j = 0; j < s.capacity(); j++) 
    {
        s[j] = "changed5";
        assert(s[j] != k[j]);
    }

    // Const Object Test
    cout << "\nConst Object Test\n";
    assert(s.capacity());//if this compiles, capacity() is a getter
    assert(w[0] == w[0]);//if this compiles, there is a getter
    assert(w[-1] == w[-1]);//tests the getter's range

    return 0;
}