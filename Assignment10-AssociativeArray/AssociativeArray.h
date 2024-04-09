// Student Name: Aurelia Kisanaga
// Student ID: 1960007

#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

#include "Queue.h"

template <typename K, typename V>
class AssociativeArray
{
    struct Node
    {
        K key;
        V value;
        Node* next = nullptr;
    };

    Node* firstNode;
    V dummy;
    int siz;

public:
    AssociativeArray() { firstNode = 0; dummy = V(); siz = 0; }     // main constructor
    AssociativeArray(const AssociativeArray<K, V>&);    // copy constructor
    AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);   // assignment operator
    ~AssociativeArray();        // destructor
    V operator[] (const K&) const;  // getter
    V& operator[] (const K&);       // setter
    bool containsKey(const K&) const;
    void deleteKey(const K&);
    Queue<K> keys() const;
    int size() const { return siz; };
    void clear();
};

// Copy Constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
    firstNode = 0;
    Node* lastNode = 0; // temporary tail
    siz = original.siz;
    for (Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->key = p->key;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}

// Assignment Operator
template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>:: operator=(const AssociativeArray<K, V>& original)
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
            temp->key = p->key;
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
template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
    }
}

// Square Bracket Operator Getter
template <typename K, typename V>
V AssociativeArray<K, V>::operator[] (const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return p->value;
    return V();
}

// Square Bracket Operator Setter
template <typename K, typename V>
V& AssociativeArray<K, V>::operator[] (const K& key)
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return p->value;
    ++siz;
    Node* temp = new Node;
    temp->key = key;
    temp->value = V();
    temp->next = firstNode;
    firstNode = temp;
    return firstNode->value;
}

// containsKey function
template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
    for (Node* p = firstNode; p; p = p->next)
        if (p->key == key)
            return true;
    return false;
}

// deleteKey function
template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
    // find the matching node
    Node* p, * prev; // declare above loop so that it survives below the loop
    for (p = firstNode, prev = 0; p; prev = p, p = p->next)
        if (p->key == key)
            break;

    // if found (that is, p did not run off the end of the list)
    if (p)
    {
        --siz;
        if (prev) prev->next = p->next; // skips over the node at p
        else firstNode = p->next; // there's a new head, possibly zero 
        delete p; // we're done with this node
    }
}

// Queue key
template <typename K, typename V>
Queue<K> AssociativeArray<K, V>::keys() const
{
    Queue<K> queue;
    for (Node* p = firstNode; p; p = p->next)
        queue.push(p->key);
    return queue;
}

// clear operator
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}




#endif