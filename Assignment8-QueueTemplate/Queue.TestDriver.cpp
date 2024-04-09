// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cassert>

#include "Queue.h"
#include "Queue.h"  //ifndef test

using namespace std;

// int, string
int main()
{
    // Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";

    // Initialization
    int size = 0;

    // TEST FOR INT
    cout << "\nTest for Integer\n";
    Queue<int> testInteger;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testInteger.size() << "\n";

    // Queue::push, Queue::front, Queue::back, Queue::pop
    cout << "\nTest for push, front, back, pop operations\n";
    testInteger.push(2);
    testInteger.push(3);
    testInteger.push(4);
    testInteger.push(5);
    assert(testInteger.front() == 2);
    assert(testInteger.back() == 5);
    cout << "4 integers pushed\n";
    cout << "Expected most front integer: 2" << endl;
    cout << "Actual most front integer: " << testInteger.front() << endl;
    cout << "Expected most back integer: 5" << endl;
    cout << "Actual most back integer: " << testInteger.back() << endl;
    testInteger.pop();
    cout << "1 integer is popped\n";
    cout << "Expected most front integer: 3" << endl;
    cout << "Actual most front integer: " << testInteger.front() << endl;
    cout << "Expected most back integer: 5" << endl;
    cout << "Actual most back integer: " << testInteger.back() << endl;
    testInteger.pop();
    cout << "Another 1 integer is popped\n";
    cout << "Expected most front integer: 4" << endl;
    cout << "Actual most front integer: " << testInteger.front() << endl;
    cout << "Expected most back integer: 5" << endl;
    cout << "Actual most back integer: " << testInteger.back() << endl;

    // Test queue copy constructor
    cout << "\nTest for Copy Constructor\n";
    testInteger.push(4);
    testInteger.push(5);
    Queue<int> copyInteger = testInteger;
    size = copyInteger.size();
    for (int i = 0; i < size; i++)
    {
        assert(copyInteger.front() == testInteger.front());
        assert(copyInteger.back() == testInteger.back());
        copyInteger.pop();
        testInteger.pop();
    }

    // Test queue assignment operator
    cout << "\nTest for Assignment Operator\n";
    testInteger.push(4);
    testInteger.push(5);
    testInteger.push(6);
    Queue<int> assignInteger = testInteger;
    size = assignInteger.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignInteger.front() == testInteger.front());
        assert(assignInteger.back() == testInteger.back());
        assignInteger.pop();
        testInteger.pop();
    }

    // Test for clear operator
    cout << "\nTest for Clear Operator\n";
    testInteger.push(4);
    testInteger.push(5);
    testInteger.push(6);
    cout << "3 elements pushed\n";
    testInteger.clear();
    cout << "Queue is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testInteger.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testInteger.empty());

    // Test for const object 
    cout << "\nConstant Object Test\n";
    const Queue<int> constInteger = testInteger;


    // TEST FOR STRING
    cout << "\nTest for String\n";
    Queue<string> testStr;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testStr.size() << "\n";

    // Queue::push, Queue::front, Queue::back, Queue::pop
    cout << "\nTest for push, front, back, pop operations\n";
    testStr.push("abc");
    testStr.push("def");
    testStr.push("ghi");
    assert(testStr.front() == "abc");
    assert(testStr.back() == "ghi");
    cout << "3 strings pushed\n";
    cout << "Expected most front string: abc" << endl;
    cout << "Actual most front integer: " << testStr.front() << endl;
    cout << "Expected most back integer: ghi" << endl;
    cout << "Actual most back integer: " << testStr.back() << endl;
    testStr.pop();
    cout << "1 string is popped\n";
    cout << "Expected most front integer: def" << endl;
    cout << "Actual most front integer: " << testStr.front() << endl;
    cout << "Expected most back integer: ghi" << endl;
    cout << "Actual most back integer: " << testStr.back() << endl;

    // Test queue copy constructor
    cout << "\nTest for Copy Constructor\n";
    testStr.push("xyz");
    testStr.push("abc");
    Queue<string> copyStr = testStr;
    size = copyStr.size();
    for (int i = 0; i < size; i++)
    {
        assert(copyStr.front() == testStr.front());
        assert(copyStr.back() == testStr.back());
        copyStr.pop();
        testStr.pop();
    }

    // Test queue assignment operator
    cout << "\nTest for Assignment Operator\n";
    testStr.push("xyz");
    testStr.push("abc");
    Queue<string> assignStr = testStr;
    size = assignStr.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignStr.front() == testStr.front());
        assert(assignStr.back() == testStr.back());
        assignStr.pop();
        testStr.pop();
    }

    // Test for clear operator
    cout << "\nTest for Clear Operator\n";
    testStr.push("xyz");
    testStr.push("abc");
    cout << "2 elements pushed\n";
    testStr.clear();
    cout << "Queue is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testStr.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testStr.empty());

    // Test for const object 
    cout << "\nConstant Object Test\n";
    const Queue<string> constStr = testStr;

    return 0;
}
