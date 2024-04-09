// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#ifndef STACK_H
#define STACK_H

template <typename V>
class Stack
{
    struct Node
    {
        V value;
        Node* next;
    };

    Node* firstNode; // the head pointer
    int siz; // tracking the number of nodes
    V dummy;

public:
    Stack();   // main constructor
    Stack(const Stack<V>&); // copy constructor
    ~Stack();
    Stack<V>& operator=(const Stack<V>&); // assignment operator
    void push(const V&);
    const V& peek() const;
    void pop();
    void clear();
    int size() const;
    bool empty() const;
};

// Main Constructor
template <typename V>
Stack<V>::Stack()
{
    firstNode = 0;
    siz = 0;
    dummy = V();
};

// Copy Constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
    firstNode = 0;
    Node* lastNode = 0; // temporary tail
    siz = original.siz;
    for (Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}

// Destructor 
template <typename V>
Stack<V>::~Stack()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

// Assignment Operator
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
    if (this != &original)
    {
        // deallocate existing list
        while (firstNode)
        {
            Node* p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }

        // build new queue
        Node* lastNode = 0; // temporary tail
        for (Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode) lastNode->next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}

// Push Operator
template <typename V>
void Stack<V>::push(const V& value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = firstNode;
    firstNode = temp;
    ++siz;
}

// Peek Operator
template <typename V>
const V& Stack<V>::peek() const
{
    if (firstNode == 0) return dummy;
    return firstNode->value;
}

// Pop Operator
template <typename V>
void Stack<V>::pop()
{
    if (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

// Clear Operator
template <typename V>
void Stack<V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

// Size Operator
template <typename V>
int Stack<V>::size() const
{
    return siz;
}

// Empty Operator
template <typename V>
bool Stack<V>::empty() const
{
    if (this->peek() == dummy)
        return true;
    return false;
}


#endif
