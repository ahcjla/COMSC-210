// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#include <iostream>
#include <cassert>
#include "Stack.h"
#include "Stack.h"  //ifndef test
using namespace std;

// int, double, char, string
int main2()
{
    // Programmer's Info
    cout << "Programmer: Aurelia Kisanaga\n";
    cout << "Programmer's ID: 1960007\n";
    cout << "File: " << __FILE__ << "\n";

    // Initialization
    int size = 0;

    // 1.
    // Test for int 
    cout << "\nTest for Integer\n";
    Stack<int> testInteger;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testInteger.size() << "\n";

    // Stack::push, Stack::peek, Stack::pop
    cout << "\nTest for push, peek, pop operator\n";
    cout << "Test for push operator\n";
    testInteger.push(1);
    testInteger.push(2);
    testInteger.push(3);
    testInteger.push(4);
    testInteger.push(5);
    cout << "5 elements pushed\n";
    cout << "Now expected size: 5\n";
    cout << "Actual size: " << testInteger.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: 5\n";
    cout << "Actual: " << testInteger.peek() << "\n";
    testInteger.pop();
    testInteger.pop();
    cout << "2 elements popped\n";
    cout << "Now expected size: 3\n";
    cout << "Actual size: " << testInteger.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: 3\n";
    cout << "Actual: " << testInteger.peek() << "\n";

    // Test stack copy constructor
    cout << "\nTest for Copy Constructor\n";
    testInteger.push(4);
    testInteger.push(5);
    Stack<int> copyInteger = testInteger;
    size = copyInteger.size();
    for (int i = 0; i < size; i++) 
    {
        assert(copyInteger.peek() == testInteger.peek());
        copyInteger.pop();
        testInteger.pop();
    }

    // Test stack assignment operator
    cout << "\nTest for Assignment Operator\n";
    testInteger.push(4);
    testInteger.push(5);
    testInteger.push(6);
    Stack<int> assignInteger = testInteger;
    size = assignInteger.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignInteger.peek() == testInteger.peek());
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
    cout << "Stack is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testInteger.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testInteger.empty());


    // 2.
    // Test for double 
    cout << "\nTest for Double\n";
    Stack<double> testDouble;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testDouble.size() << "\n";

    // Stack::push, Stack::peek, Stack::pop
    cout << "\nTest for push, peek, pop operator\n";
    cout << "Test for push operator\n";
    testDouble.push(1.23);
    testDouble.push(3.45);
    testDouble.push(5.67);
    testDouble.push(7.89);
    cout << "4 elements pushed\n";
    cout << "Now expected size: 4\n";
    cout << "Actual size: " << testDouble.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: 7.89\n";
    cout << "Actual: " << testDouble.peek() << "\n";
    testDouble.pop();
    testDouble.pop();
    cout << "2 elements popped\n";
    cout << "Now expected size: 2\n";
    cout << "Actual size: " << testDouble.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: 3.45\n";
    cout << "Actual: " << testDouble.peek() << "\n";

    // Test stack copy constructor
    cout << "\nTest for Copy Constructor\n";
    testDouble.push(5.67);
    testDouble.push(7.89);
    Stack<double> copyDouble = testDouble;
    size = copyDouble.size();
    for (int i = 0; i < size; i++)
    {
        assert(copyDouble.peek() == testDouble.peek());
        copyDouble.pop();
        testDouble.pop();
    }

    // Test stack assignment operator
    cout << "\nTest for Assignment Operator\n";
    testDouble.push(5.67);
    testDouble.push(7.89);
    Stack<double> assignDouble = testDouble;
    size = assignDouble.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignDouble.peek() == testDouble.peek());
        assignDouble.pop();
        testDouble.pop();
    }

    // Test for clear operator
    cout << "\nTest for Clear Operator\n";
    testDouble.push(3.45);
    testDouble.push(5.67);
    testDouble.push(7.89);
    cout << "3 elements pushed\n";
    testDouble.clear();
    cout << "Stack is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testDouble.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testDouble.empty());


    // 3.
    // Test for char
    cout << "\nTest for Char\n";
    Stack<char> testChar;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testChar.size() << "\n";

    // Stack::push, Stack::peek, Stack::pop
    cout << "\nTest for push, peek, pop operator\n";
    cout << "Test for push operator\n";
    testChar.push('a');
    testChar.push('b');
    testChar.push('c');
    cout << "3 elements pushed\n";
    cout << "Now expected size: 3\n";
    cout << "Actual size: " << testChar.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: c\n";
    cout << "Actual: " << testChar.peek() << "\n";
    testChar.pop();
    testChar.pop();
    cout << "2 elements popped\n";
    cout << "Now expected size: 1\n";
    cout << "Actual size: " << testChar.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: a\n";
    cout << "Actual: " << testChar.peek() << "\n";

    // Test stack copy constructor
    cout << "\nTest for Copy Constructor\n";
    testChar.push('b');
    testChar.push('c');
    Stack<char> copyChar = testChar;
    size = copyChar.size();
    for (int i = 0; i < size; i++)
    {
        assert(copyChar.peek() == testChar.peek());
        copyChar.pop();
        testChar.pop();
    }

    // Test stack assignment operator
    cout << "\nTest for Assignment Operator\n";
    testChar.push('b');
    testChar.push('c');
    Stack<char> assignChar = testChar;
    size = assignChar.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignChar.peek() == testChar.peek());
        assignChar.pop();
        testChar.pop();
    }

    // Test for clear operator
    cout << "\nTest for Clear Operator\n";
    testChar.push('a');
    testChar.push('b');
    testChar.push('c');
    testChar.push('d');
    testChar.push('e');
    testChar.push('f');
    cout << "6 elements pushed\n";
    testChar.clear();
    cout << "Stack is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testChar.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testChar.empty());


    // 4.
    // Test for string
    cout << "\nTest for String\n";
    Stack<string> testStr;

    // Initial Size
    cout << "\nTest for initial size\n";
    cout << "Expected: 0\n";
    cout << "Actual: " << testStr.size() << "\n";

    // Stack::push, Stack::peek, Stack::pop
    cout << "\nTest for push, peek, pop operator\n";
    cout << "Test for push operator\n";
    testStr.push("abc");
    testStr.push("def");
    testStr.push("ghi");
    testStr.push("xyz");
    cout << "4 elements pushed\n";
    cout << "Now expected size: 4\n";
    cout << "Actual size: " << testStr.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: xyz\n";
    cout << "Actual: " << testStr.peek() << "\n";
    testStr.pop();
    testStr.pop();
    cout << "2 elements popped\n";
    cout << "Now expected size: 2\n";
    cout << "Actual size: " << testStr.size() << "\n";
    cout << "Test for peek operator\n";
    cout << "Expected: def\n";
    cout << "Actual: " << testStr.peek() << "\n";

    // Test stack copy constructor
    cout << "\nTest for Copy Constructor\n";
    testStr.push("ghi");
    testStr.push("xyz");
    Stack<string> copyStr = testStr;
    size = copyStr.size();
    for (int i = 0; i < size; i++)
    {
        assert(copyStr.peek() == testStr.peek());
        copyStr.pop();
        testStr.pop();
    }

    // Test stack assignment operator
    cout << "\nTest for Assignment Operator\n";
    testStr.push("abc");
    testStr.push("def");
    Stack<string> assignStr = testStr;
    size = assignStr.size();
    for (int i = 0; i < size; i++)
    {
        assert(assignStr.peek() == testStr.peek());
        assignStr.pop();
        testStr.pop();
    }

    // Test for clear operator
    cout << "\nTest for Clear Operator\n";
    testStr.push("abc");
    testStr.push("def");
    testStr.push("ghi");
    testStr.push("xyz");
    cout << "4 elements pushed\n";
    testStr.clear();
    cout << "Stack is now cleared\n";
    cout << "Expected size: 0\n";
    cout << "Actual: " << testStr.size() << endl;

    // Test for empty operator 
    cout << "\nTest for Empty Operator\n";
    assert(testStr.empty());
        
    return 0;



}