//
// Created by alsha on 10/15/2021.
//
// 1st programmer name: Aiman Al Sharai
// 1st programmer ID: 1839435
//
// 2nd programmer name: Aurelia Kisanaga
// 2nd programmer ID: 1960007


#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "Queue.h" // test for if-else correctness

#include <cassert>

void testIntQueue( ); // test driver for Queue of type int
void testDoubleQueue( ); // test driver for Queue of type double
void testStrQueue( ); // test driver for Queue of type string
void testCharQueue( ); // test driver for Queue of type char

int queueTestMain( )
{
  testIntQueue();

  testDoubleQueue( );

  testStrQueue();

  testCharQueue();

    return 0;

}

void testIntQueue( )
{
  // initialize Queue of type int
  Queue<int> queue;

  // Queue<int>
  cout << "\nTesting Queue<int>\n";

  // Queue<int>::push()
  cout <<"\nTesting Queue<int>::push()\n";
  cout << "Adding 1 to the queue\n";
  queue.push(1);
  cout << "Adding 2 to the queue\n";
  queue.push(2);
  cout << "Adding 3 to the queue\n";
  queue.push(3);

  // Queue<int>::size()
  cout <<"\nTesting Queue<int>::size()\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << queue.size() <<endl;
  assert(3 == queue.size());

  // Queue<int>::front()
  cout <<"\nTesting Queue<int>::front()\n";
  cout << "EXPECTED: 1\n";
  cout << "ACTUAL: " << queue.front() <<endl;
  assert(1 == queue.front());

  // Queue<int>::back()
  cout <<"\nTesting Queue<int>::back()\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << queue.back() <<endl;
  assert(3 == queue.back());

  // Copy object test
  cout <<"\nCopy object test\n";
  Queue<int> copy = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copy.size() << endl;
  cout << "EXPECTED FRONT: 1\n";
  cout << "ACTUAL FRONT: " << copy.front() << endl;
  cout << "EXPECTED BACK: 3\n";
  cout << "ACTUAL FRONT: " << copy.back() << endl;
  assert(queue.size() == copy.size());
  assert(queue.front() == copy.front());
  assert(queue.back() == copy.back());

  // const copy queue
  const Queue<int> conCopy = queue;
  cout <<"\nConstant copy queue\n";
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << conCopy.size() << endl;
  cout << "EXPECTED FRONT: 1\n";
  cout << "ACTUAL FRONT: " << conCopy.front() << endl;
  cout << "EXPECTED BACK: 3\n";
  cout << "ACTUAL FRONT: " << conCopy.back() << endl;
  assert(queue.size() == conCopy.size());
  assert(queue.front() == conCopy.front());
  assert(queue.back() == conCopy.back());

  //conCopy.pop()
  //conCopy.pop(); method for a constant object will throw an error which shows the correctness of implementation.

  //Queue<int>::operator=
  cout << "\nTesting Queue<int>::operator=\n";
  Queue<int> copyB;
  copyB = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copyB.size() << endl;
  cout << "EXPECTED FRONT: 1\n";
  cout << "ACTUAL FRONT: " << copyB.front() << endl;
  cout << "EXPECTED BACK: 3\n";
  cout << "ACTUAL FRONT: " << copyB.back() << endl;
  assert(queue.size() == copyB.size());
  assert(queue.front() == copyB.front());
  assert(queue.back() == copyB.back());

  // Queue<int>::Queue(const Queue<int>&>) && Queue<int>::operator=
  cout << "Fully testing for Queue<int>::Queue(const Queue<int>&>) && operator=\n";

  while(!queue.empty( ))
  {
    cout << "copy.front(): " << copy.front() << " | queue.front(): " << queue.front() << endl;
    assert(copy.front() == queue.front());
    cout << "copy.back(): " << copy.back() << " | queue.peek(): " << queue.back() << endl;
    assert(copy.back() == queue.back());
    queue.pop();
    copy.pop();
  }

  // Queue<int>::push()
  cout <<"\nTesting Queue<int>::push()\n";
  cout << "Adding 4 to the queue\n";
  queue.push(4);
  cout << "Adding 5 to the queue\n";
  queue.push(5);

  // Queue<int>::empty()
  cout << "\nTesting Queue<int>::empty()\n";
  cout << "EXPECTED: false\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == false);

  // Queue<int>::empty()
  queue.clear();
  cout << "\nTesting Queue<int>::clear()\n";
  cout << "EXPECTED SIZE: 0\n";
  cout << "ACTUAL SIZE: " << queue.size() << endl;
  cout << "EXPECTED empty(): True\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == true);

}

void testDoubleQueue( )
{
  // initialize Queue of type double
  Queue<double> queue;

  // Queue<double>
  cout << "\nTesting Queue<double>\n";

  // Queue<double>::push()
  cout <<"\nTesting Queue<double>::push()\n";
  cout << "Adding 1.1 to the queue\n";
  queue.push(1.1);
  cout << "Adding 2.2 to the queue\n";
  queue.push(2.2);
  cout << "Adding 3.0 to the queue\n";
  queue.push(3.0);

  // Queue<double>::size()
  cout <<"\nTesting Queue<double>::size()\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << queue.size() <<endl;
  assert(3 == queue.size());

  // Queue<double>::front()
  cout <<"\nTesting Queue<double>::front()\n";
  cout << "EXPECTED: 1.1\n";
  cout << "ACTUAL: " << queue.front() <<endl;
  assert(1.1 == queue.front());

  // Queue<double>::back()
  cout <<"\nTesting Queue<double>::back()\n";
  cout << "EXPECTED: 3.0\n";
  cout << "ACTUAL: " << queue.back() <<endl;
  assert(3.0 == queue.back());

  // Copy object test
  cout <<"\nCopy object test\n";
  Queue<double> copy = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copy.size() << endl;
  cout << "EXPECTED FRONT: 1.1\n";
  cout << "ACTUAL FRONT: " << copy.front() << endl;
  cout << "EXPECTED BACK: 3.0\n";
  cout << "ACTUAL FRONT: " << copy.back() << endl;
  assert(queue.size() == copy.size());
  assert(queue.front() == copy.front());
  assert(queue.back() == copy.back());

  // const copy queue
  const Queue<double> conCopy = queue;
  cout <<"\nConstant copy queue\n";
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << conCopy.size() << endl;
  cout << "EXPECTED FRONT: 1.1\n";
  cout << "ACTUAL FRONT: " << conCopy.front() << endl;
  cout << "EXPECTED BACK: 3.0\n";
  cout << "ACTUAL FRONT: " << conCopy.back() << endl;
  assert(queue.size() == conCopy.size());
  assert(queue.front() == conCopy.front());
  assert(queue.back() == conCopy.back());

  //conCopy.pop()
  //conCopy.pop(); method for a constant object will throw an error which shows the correctness of implementation.

  //Queue<double>::operator=
  cout << "\nTesting Queue<double>::operator=\n";
  Queue<double> copyB;
  copyB = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copyB.size() << endl;
  cout << "EXPECTED FRONT: 1.1\n";
  cout << "ACTUAL FRONT: " << copyB.front() << endl;
  cout << "EXPECTED BACK: 3.0\n";
  cout << "ACTUAL FRONT: " << copyB.back() << endl;
  assert(queue.size() == copyB.size());
  assert(queue.front() == copyB.front());
  assert(queue.back() == copyB.back());

  // Queue<double>::Queue(const Queue<double>&>) && Queue<double>::operator=
  cout << "Fully testing for Queue<double>::Queue(const Queue<double>&>) && operator=\n";

  while(!queue.empty( ))
  {
    cout << "copy.front(): " << copy.front() << " | queue.front(): " << queue.front() << endl;
    assert(copy.front() == queue.front());
    cout << "copy.back(): " << copy.back() << " | queue.peek(): " << queue.back() << endl;
    assert(copy.back() == queue.back());
    queue.pop();
    copy.pop();
  }

  // Queue<double>::push()
  cout <<"\nTesting Queue<double>::push()\n";
  cout << "Adding 4.0 to the queue\n";
  queue.push(4.0);
  cout << "Adding 5.5 to the queue\n";
  queue.push(5.5);

  // Queue<double>::empty()
  cout << "\nTesting Queue<double>::empty()\n";
  cout << "EXPECTED: false\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == false);

  // Queue<double>::empty()
  queue.clear();
  cout << "\nTesting Queue<double>::clear()\n";
  cout << "EXPECTED SIZE: 0\n";
  cout << "ACTUAL SIZE: " << queue.size() << endl;
  cout << "EXPECTED empty(): True\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == true);
}

void testStrQueue( )
{
  // initialize Queue of type string
  Queue<string> queue;

  // Queue<string>
  cout << "\nTesting Queue<string>\n";

  // Queue<string>::push()
  cout <<"\nTesting Queue<string>::push()\n";
  cout << "Adding stringA to the queue\n";
  queue.push("stringA");
  cout << "Adding stringB to the queue\n";
  queue.push("stringB");
  cout << "Adding stringC to the queue\n";
  queue.push("stringC");

  // Queue<string>::size()
  cout <<"\nTesting Queue<string>::size()\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << queue.size() <<endl;
  assert(3 == queue.size());

  // Queue<double>::front()
  cout <<"\nTesting Queue<double>::front()\n";
  cout << "EXPECTED: stringA\n";
  cout << "ACTUAL: " << queue.front() <<endl;
  assert("stringA" == queue.front());

  // Queue<string>::back()
  cout <<"\nTesting Queue<string>::back()\n";
  cout << "EXPECTED: stringC\n";
  cout << "ACTUAL: " << queue.back() <<endl;
  assert("stringC" == queue.back());

  // Copy object test
  cout <<"\nCopy object test\n";
  Queue<string> copy = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copy.size() << endl;
  cout << "EXPECTED FRONT: stringA\n";
  cout << "ACTUAL FRONT: " << copy.front() << endl;
  cout << "EXPECTED BACK: stringC\n";
  cout << "ACTUAL FRONT: " << copy.back() << endl;
  assert(queue.size() == copy.size());
  assert(queue.front() == copy.front());
  assert(queue.back() == copy.back());

  // const copy queue
  const Queue<string> conCopy = queue;
  cout <<"\nConstant copy queue\n";
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << conCopy.size() << endl;
  cout << "EXPECTED FRONT: stringA\n";
  cout << "ACTUAL FRONT: " << conCopy.front() << endl;
  cout << "EXPECTED BACK: stringC\n";
  cout << "ACTUAL FRONT: " << conCopy.back() << endl;
  assert(queue.size() == conCopy.size());
  assert(queue.front() == conCopy.front());
  assert(queue.back() == conCopy.back());

  //conCopy.pop()
  //conCopy.pop(); method for a constant object will throw an error which shows the correctness of implementation.

  //Queue<string>::operator=
  cout << "\nTesting Queue<string>::operator=\n";
  Queue<string> copyB;
  copyB = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copyB.size() << endl;
  cout << "EXPECTED FRONT: stringA\n";
  cout << "ACTUAL FRONT: " << copyB.front() << endl;
  cout << "EXPECTED BACK: stringC\n";
  cout << "ACTUAL FRONT: " << copyB.back() << endl;
  assert(queue.size() == copyB.size());
  assert(queue.front() == copyB.front());
  assert(queue.back() == copyB.back());

  // Queue<string>::Queue(const Queue<string>&>) && Queue<string>::operator=
  cout << "Fully testing for Queue<string>::Queue(const Queue<string>&>) && operator=\n";

  while(!queue.empty( ))
  {
    cout << "copy.front(): " << copy.front() << " | queue.front(): " << queue.front() << endl;
    assert(copy.front() == queue.front());
    cout << "copy.back(): " << copy.back() << " | queue.peek(): " << queue.back() << endl;
    assert(copy.back() == queue.back());
    queue.pop();
    copy.pop();
  }

  // Queue<string>::push()
  cout <<"\nTesting Queue<string>::push()\n";
  cout << "Adding stringD to the queue\n";
  queue.push("stringD");
  cout << "Adding stringF to the queue\n";
  queue.push("stringF");

  // Queue<string>::empty()
  cout << "\nTesting Queue<string>::empty()\n";
  cout << "EXPECTED: false\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == false);

  // Queue<string>::empty()
  queue.clear();
  cout << "\nTesting Queue<string>::clear()\n";
  cout << "EXPECTED SIZE: 0\n";
  cout << "ACTUAL SIZE: " << queue.size() << endl;
  cout << "EXPECTED empty(): True\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == true);
}

void testCharQueue( )
{
  // initialize Queue of type char
  Queue<char> queue;

  // Queue<char>
  cout << "\nTesting Queue<char>\n";

  // Queue<char>::push()
  cout <<"\nTesting Queue<char>::push()\n";
  cout << "Adding A to the queue\n";
  queue.push('A');
  cout << "Adding B to the queue\n";
  queue.push('B');
  cout << "Adding C to the queue\n";
  queue.push('C');

  // Queue<char>::size()
  cout <<"\nTesting Queue<char>::size()\n";
  cout << "EXPECTED: 3\n";
  cout << "ACTUAL: " << queue.size() <<endl;
  assert(3 == queue.size());

  // Queue<char>::front()
  cout <<"\nTesting Queue<double>::front()\n";
  cout << "EXPECTED: A\n";
  cout << "ACTUAL: " << queue.front() <<endl;
  assert('A' == queue.front());

  // Queue<char>::back()
  cout <<"\nTesting Queue<char>::back()\n";
  cout << "EXPECTED: C\n";
  cout << "ACTUAL: " << queue.back() <<endl;
  assert('C' == queue.back());

  // Copy object test
  cout <<"\nCopy object test\n";
  Queue<char> copy = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copy.size() << endl;
  cout << "EXPECTED FRONT: A\n";
  cout << "ACTUAL FRONT: " << copy.front() << endl;
  cout << "EXPECTED BACK: C\n";
  cout << "ACTUAL FRONT: " << copy.back() << endl;
  assert(queue.size() == copy.size());
  assert(queue.front() == copy.front());
  assert(queue.back() == copy.back());

  // const copy queue
  const Queue<char> conCopy = queue;
  cout <<"\nConstant copy queue\n";
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << conCopy.size() << endl;
  cout << "EXPECTED FRONT: A\n";
  cout << "ACTUAL FRONT: " << conCopy.front() << endl;
  cout << "EXPECTED BACK: C\n";
  cout << "ACTUAL FRONT: " << conCopy.back() << endl;
  assert(queue.size() == conCopy.size());
  assert(queue.front() == conCopy.front());
  assert(queue.back() == conCopy.back());

  //conCopy.pop()
  //conCopy.pop(); method for a constant object will throw an error which shows the correctness of implementation.

  //Queue<char>::operator=
  cout << "\nTesting Queue<char>::operator=\n";
  Queue<char> copyB;
  copyB = queue;
  cout << "EXPECTED SIZE: 3\n";
  cout << "ACTUAL Size: " << copyB.size() << endl;
  cout << "EXPECTED FRONT: A\n";
  cout << "ACTUAL FRONT: " << copyB.front() << endl;
  cout << "EXPECTED BACK: C\n";
  cout << "ACTUAL FRONT: " << copyB.back() << endl;
  assert(queue.size() == copyB.size());
  assert(queue.front() == copyB.front());
  assert(queue.back() == copyB.back());

  // Queue<char>::Queue(const Queue<char>&>) && Queue<char>::operator=
  cout << "Fully testing for Queue<char>::Queue(const Queue<char>&>) && operator=\n";

  while(!queue.empty( ))
  {
    cout << "copy.front(): " << copy.front() << " | queue.front(): " << queue.front() << endl;
    assert(copy.front() == queue.front());
    cout << "copy.back(): " << copy.back() << " | queue.peek(): " << queue.back() << endl;
    assert(copy.back() == queue.back());
    queue.pop();
    copy.pop();
  }

  // Queue<char>::push()
  cout <<"\nTesting Queue<string>::push()\n";
  cout << "Adding D to the queue\n";
  queue.push('D');
  cout << "Adding F to the queue\n";
  queue.push('F');

  // Queue<char>::empty()
  cout << "\nTesting Queue<char>::empty()\n";
  cout << "EXPECTED: false\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == false);

  // Queue<char>::empty()
  queue.clear();
  cout << "\nTesting Queue<char>::clear()\n";
  cout << "EXPECTED SIZE: 0\n";
  cout << "ACTUAL SIZE: " << queue.size() << endl;
  cout << "EXPECTED empty(): True\n";
  cout << "ACTUAL: " << (queue.empty()? "Ture":"False") << endl;
  assert(queue.empty() == true);
}
