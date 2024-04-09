// Student Name: Aurelia Kisanaga
// Student ID: 1960007

#ifndef QUEUE_H
#define QUEUE_H

template <typename V>
class Queue
{
    struct Node
    {
        V value;
        Node* next;
    };
    int siz;
    Node* firstNode;
    Node* lastNode;
    V dummy;

public:
    Queue();        // main constructor
    Queue(const Queue&);   // copy constructor
    Queue<V>& operator = (const Queue<V>&);     // assignment operator
    ~Queue();               // destructor
    void push(const V&);
    const V& front() const;     // return an immutable reference to the oldest node
    const V& back() const;      // return an immutable reference to the newest node
    void pop();     // remove the oldest node
    int size() const { return siz; }
    bool empty() const { return siz == 0; }
    void clear();
};

// Main Constructor
template <typename V>
Queue<V>::Queue()
{
    firstNode = 0;
    lastNode = 0;
    siz = 0;
    dummy = V();
}

// Copy Constructor
template <typename V>
Queue<V>::Queue(const Queue& original)
{
    firstNode = 0;
    lastNode = 0; // temporary tail
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

// Assignment Operator 
template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original)
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
        lastNode = 0; // temporary tail
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

// Destructor
template <typename V>
Queue<V>::~Queue()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

// Push Operator
template <typename V>
void Queue<V>::push(const V& value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
    ++siz;
}

// Front Function
template <typename V>
const V& Queue<V>::front() const
{
    if (siz == 0) return dummy;
    return firstNode->value;
}

// Back Function
template <typename V>
const V& Queue<V>::back() const
{
    if (siz == 0) return dummy;
    return lastNode->value;
}

// Pop Operation
template <typename V>
void Queue<V>::pop()
{
    if (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
        if (siz == 0) lastNode = 0;
    }
}

// Clear Operation
template <typename V>
void Queue<V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
        if (siz == 0) lastNode = 0;
    }
}

#endif
