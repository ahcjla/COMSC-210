// Programmer's name: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "AssociativeArray.h"
#include "AssociativeArray.h" // ifndef test

struct testType
{
    double num;
    testType(int a) :num(a) {}
};

struct testKey
{
    string tKey;
    testKey(string s) :tKey(s) {}
};

int main2()
{
    // Display Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";
    cout << endl;

    AssociativeArray<string, double> a;

    //AssociativeArray::AssociativeArray & size() 
    cout << "AssociativeArray test\n"
        << "----------------------------\n"
        << "Testing AssociativeArray::AssociativeArray & size()\n";
    assert(a.size() == 0);
    cout << "Pass!\n\n";

    //AssociativeArray::operator [ ] setter 
    cout << "Testing AssociativeArray::operator [ ] setter \n";
    a["A"];
    assert(a["A"] == double());
    assert(a.size() == 1);
    cout << "Pass!\n\n";
    a["A"] = 1.1;

    //AssociativeArray::copy constructor 
    cout << "Tesing copy constructor\n";
    a["B"] = 2.2;
    AssociativeArray<string, double> b = a;
    assert(b.size() == a.size());
    assert(b["A"] == 1.1);
    assert(b["B"] == 2.2);
    assert(b.size() == 2);
    cout << "Pass!\n\n";

    //AssociativeArray::operator [ ] setter
    cout << "Testing operator [ ] getter\n";
    const AssociativeArray<string, double> c = a;
    assert(c["A"] == 1.1);
    assert(c["B"] == 2.2);
    cout << "Pass!\n\n";

    //assignment operator
    cout << "Testing assignment operator\n";
    AssociativeArray<string, double> d;
    d = a;
    assert(d.size() == a.size());
    assert(d["A"] == 1.1);
    assert(d["B"] == 2.2);
    cout << "Pass!\n\n";

    //AssociativeArray::containsKey
    cout << "Testing AssociativeArray::containsKey\n";
    assert(a.containsKey("A"));
    assert(!a.containsKey("D"));
    cout << "Pass!\n\n";

    //AssociativeArray::deleteKey
    cout << "Testing AssociativeArray::deleteKey\n";
    a.deleteKey("A");
    //a.deleteKey("s");
    assert(!a.containsKey("A"));
    cout << "Pass!\n\n";

    //AssociativeArray::isKey
    cout << "Testing AssociativeArray::isKey\n";
    Queue<string> keys = d.keys();
    assert(keys.front() == "B");
    keys.pop();
    assert(keys.front() == "A");
    cout << "Pass!\n\n";

    //2D test
    cout << "Testing 2D array\n";
    AssociativeArray<string, AssociativeArray<string, bool> > e;
    e["A"]["B"] = true;
    e["A"]["C"] = false;
    assert(e["A"]["B"]);
    assert(!e["A"]["C"]);
    cout << "Pass!\n\n";

    //clear
    cout << "Testing AssociativeArray::clear\n";
    e.clear();
    assert(e.size() == 0);
    cout << "Pass!\n\n";

    return 0;
}