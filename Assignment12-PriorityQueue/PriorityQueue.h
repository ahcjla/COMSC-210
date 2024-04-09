// Programmer: Aurelia Kisanaga 
// Programmer's ID: 1960007

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template<typename V>
class PriorityQueue
{
    V* values;
    int cap;
    int siz;
    void capacity(int);

public:
    PriorityQueue(int = 2);
    PriorityQueue(const PriorityQueue<V>&);
    ~PriorityQueue() {delete[] values;};
    PriorityQueue<V>& operator=(const PriorityQueue<V>&);

    void push(const V&);
    void pop();
    V top() const {return siz == 0 ? V() : values[0];}
    int size() const {return siz;}
    bool empty() const {return siz == 0 ? true : false;}
    void clear() {siz = 0;}
};

// Main Constructor
template <typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
    siz = 0;
    this->cap = cap;
    values = new V[cap];
}

// Copy Constructor
template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
    {
        values[i] = original.values[i];
    }
}

// Assignment Operator
template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
    if (this != &original)
    {
        delete[] values;
        cap = original.cap;
        siz = original.siz;
        values = new V[cap];
        for (int i = 0; i < cap; i++)
        {
            values[i] = original.values[i];
        }
    }
    return *this;
}

// Capacity
template <typename V>
void PriorityQueue<V>::capacity(int cap)
{
    V* temp = new V[cap];
    int limit = (cap < this->cap ? cap : this->cap);
    for (int i = 0; i < limit; i++)
    {
        temp[i] = values[i];
    }
    for (int i = limit; i < cap; i++)
    {
        temp[i] = V();
    }
    delete[] values;
    values = temp;
    this->cap = cap;
}

// Push Operator
template <typename V>
void PriorityQueue<V>::push(const V& value)
{
    if (siz == cap) capacity(2 * cap);
    values[siz] = value;
    int index = siz;
    while (index != 0)
    {
            int parentIndex = (index - 1) / 2;
            if (values[index] < values[parentIndex]) break;
            V temp = values[index];
            values[index] = values[parentIndex];
            values[parentIndex] = temp;
            index = parentIndex;
    }
    siz++;
}

// Pop Operator
template <typename V>
void PriorityQueue<V>::pop()
{
    if (siz == 0) return;
    if (!empty())
    {
        int index = 0;
        while (true)
        {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            if (siz - 1 < leftIndex) break;
            if (siz - 1 < rightIndex)
            {
                values[index] = values[leftIndex];
                index = leftIndex;
            }
            else if (values[rightIndex] < values[leftIndex])
            {
                values[index] = values[leftIndex];
                index = leftIndex;
            }
            else
            {
                values[index] = values[rightIndex];
                index = rightIndex;
            }
        }
        siz--;
        values[index] = values[siz];
        while (index != 0)
        {
            int parentIndex = (index - 1) / 2;
            if (values[index] < values[parentIndex]) break;
            V temp = values[index];
            values[index] = values[parentIndex];
            values[parentIndex] = temp;
            index = parentIndex;
        }
    }

}


#endif
