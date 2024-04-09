// Programmer Name: Alex Kogan
// Programmer ID: 1865080
// Programmer 2 Name: Rachael Karim
// Programmer 2 ID: 0136068
// Programmer 3 Name: Aiman Al Sharai
// Programmer 3 ID: 1839435
// Programmer 4 Name: Aurelia Kisanaga
// Programmer 4 ID: 1960007
// Programmer 5 Name: Steven Dominic Sahar
// Programmer 5 ID: 1855840

#include <iostream>
using namespace std;

#include "PriorityQueue.h"
#include "PriorityQueue.h" // test for if-else correctness

#include "cassert"

void intPriorityQueueTest();
void stringPriorityQueueTest();

int priorityTestMain( )
{
    intPriorityQueueTest( );

    return 0;
}

void intPriorityQueueTest( )
{
    // Initialize Priority Queue
    PriorityQueue<int> pq(3);

    cout << "\nPriorityQueue<int>\n";

    // PriorityQueue::push()
    cout <<"\nTesting PriorityQueue::push()\n";
    cout << "Adding 0 to the Priority Queue\n";
    pq.push(0);
    cout << "Adding 330 to the Priority Queue\n";
    pq.push(330);
    cout << "Adding 2 to the Priority Queue\n";
    pq.push(2);
    cout << "Adding 1 to the Priority Queue\n";
    pq.push(1);

    // PriorityQueue::size()
    cout << "\nTesting PriorityQueue::size()\n";
    cout << "EXPECTED: 4\n";
    cout << "ACTUAL: " << pq.size() << endl;
    assert(pq.size() == 4);

    // PriorityQueue::top()
    cout << "\nTesting PriorityQueue::top()\n";
    cout << "EXPECTED: 330\n";
    cout << "ACTUAL: " << pq.top() << endl;
    assert(pq.top() == 330);

    // PriorityQueue::pop()
    cout << "\nTesting PriorityQueue::pop()\n";
    pq.pop();
    cout << "EXPECTED TOP VALUE NOW: 2\n";
    cout << "ACTUAL: " << pq.top() << endl;
    assert(pq.top() == 2);

    // Copy object test
    cout <<"\nTesting copy object test\n";
    PriorityQueue<int> pqCopy = pq;
    cout << "EXPECTED SIZE: 3\n";
    cout << "ACTUAL Size: " << pqCopy.size() << endl;
    assert(pqCopy.size() == 3);
    pq.push(4);
    cout << "ACTUAL Size: " << pqCopy.size() << endl;
    assert(pqCopy.size() == 3);

    // Const copy object test
    cout <<"\nTesting const copy object test\n";
    const PriorityQueue<int> pqCopyB = pq;
    cout << "EXPECTED SIZE: 4\n";
    cout << "ACTUAL Size: " << pqCopyB.size() << endl;
    assert(pqCopyB.size() == 4);

    //pqCopyB.pop(); method for a constant object will throw an error which shows the correctness of implementation.

    // PriorityQueue::empty()
    cout << "\nTesting PriorityQueue::empty()\n";
    cout << "EXPECTED: false\n";
    cout << "ACTUAL:" << (pq.empty()? "true":"false") << endl;
    assert(pq.empty() == 0);

    // PriorityQueue::clear()
    cout << "\nTesting PriorityQueue::clear()\n";
    pq.clear();
    cout << "EXPECTED: true\n";
    cout << "ACTUAL:" << (pq.empty()? "true":"false") << endl;
    assert(pq.empty() == 1);


    pq.pop();





}