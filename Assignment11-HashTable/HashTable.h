// Programmer: Aurelia Kisanaga 
// Programmer's ID: 1960007

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include "Queue.h"

template <typename K, typename V, int CAP>
class HashTable
{
    struct Node
    {
        K key;
        V value;
    };

    list<Node> data[CAP];   // chaining
    int(*hashCode)(const K&);   // ptr to hashCode function
    int siz;

public:
    HashTable(int(*)(const K&) = 0);    // =0 for a default constructor
    double loadFactor() const { return 1.0 * siz / CAP; }
    V operator[] (const K&) const;  // getter
    V& operator[] (const K&);   // setter
    bool containsKey(const K&) const;   // getter
    void deleteKey(const K&);   // setter
    Queue<K> keys() const;
    int size() const { return siz; }
    void clear();
};

// Main constructor
template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*hashCode)(const K&))
{
    this->hashCode = hashCode;
    siz = 0;
}

// Square bracket getter
template<typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[] (const K& key) const     // getter
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
        if (it->key == key)
            break;
    if (it == data[index].end()) // not found
        return V();
    if (it != data[index].end()) // found
        return it->value;
}

// Square bracket setter
template<typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[] (const K& key)  // setter
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
        if (it->key == key)
            break;
    if (it == data[index].end()) // not found
    {
        siz++;
        Node tempNode = { key, V() }; // temporary Node
        data[index].push_back(tempNode);
        return data[index].back().value;
    }
    else
        return it->value;
}

// containsKey function (getter)
template<typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::const_iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
        if (it->key == key) break;
    if (it == data[index].end()) return false;
    return true;
}

// deleteKey function (setter)
template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key)
{
    int index = hashCode(key) % CAP;
    if (index < 0) index += CAP;
    typename list<Node>::iterator it;
    for (it = data[index].begin(); it != data[index].end(); it++)
        if (it->key == key)
            break;
    if (it == data[index].end()) // not found
        return;
    if (it != data[index].end()) // found
    {
        data[index].erase(it);
        siz--;
    }
}

// clear() function 
template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
    for (int i = 0; i < CAP; i++)
    {
        data[i].clear();
    }
    siz = 0;
}

// keys() function
template<typename K, typename V, int CAP>
Queue<K> HashTable<K, V, CAP>::keys() const
{
    Queue<K> key_queue;
    for (int i = 0; i < CAP; i++)
    {
        typename list<Node>::const_iterator it;
        for (it = data[i].begin(); it != data[i].end(); it++)
        {
            key_queue.push(it->key);
        }
    }
    return key_queue;
}

#endif
