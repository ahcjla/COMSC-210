// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

template<typename V>
class SortableArray
{
    V* value;
    V dummy;
    int cap;

public:
    SortableArray(int = 2);  // constructor // default = 2
    SortableArray(const SortableArray<V>&);   // copy constructor
    ~SortableArray() { delete[] value; }    // destructor
    SortableArray<V>& operator = (const SortableArray<V>&);   // assignment operator 

    int capacity() const { return cap; } // capacity getter
    void capacity(int);     // capacity setter
    V operator[] (int) const;   // getter
    V& operator[] (int);    // setter

    void sort(int);
};

// Main Constructor
template <typename V>
SortableArray<V>::SortableArray(int cap)
{
    dummy = V();
    this->cap = cap;
    value = new V[cap];
    for (int i = 0; i < cap; i++)
        value[i] = V();
}

// Copy Constructor
template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
    cap = original.cap;
    value = new V[cap];
    for (int i = 0; i < cap; i++)
        value[i] = original.value[i];
    dummy = original.dummy;
}


// Assignment Operator
template <typename V>
SortableArray<V>& SortableArray<V>::operator = (const SortableArray<V>& original)
{
    if (this != &original)
    {
        delete[] value;
        cap = original.cap;
        value = new V[cap];
        for (int i = 0; i < cap; i++)
            value[i] = original.value[i];
        dummy = original.dummy;
    }
    return *this;
}

// Setter Capacity
template <typename V>
void SortableArray<V>::capacity(int cap)
{
    V* temp = new V[cap];
    int limit = (cap < this->cap ? cap : this->cap);
    for (int i = 0; i < limit; i++)
        temp[i] = value[i];
    for (int i = limit; i < cap; i++)
        temp[i] = V();
    delete[] value;
    value = temp;
    this->cap = cap;
}

// Getter
template <typename V>
V SortableArray<V>::operator[](int index) const
{
    if (index < cap && index > -1)
        return value[index];
    else
        return dummy;
}

// Setter
template <typename V>
V& SortableArray<V>::operator[](int index)
{
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return value[index];
}

// Sort function using mergesort
template <typename V>
void SortableArray<V>::sort(int size)
{
    V* temp = new V[size];
    for (int delta = 1; delta < size; delta *= 2)
    {
        int index = 0;
        for (int i = 0; i < size; i++) temp[i] = value[i];
        for (int i = 0; i < size; i += 2 * delta)
        {
            int left = i;
            int leftMax = (size < left + delta ? size : left + delta);
            int right = leftMax;
            int rightMax = (size < right + delta ? size : right + delta);
            while (left < leftMax || right < rightMax)
            {
                if (left == leftMax) value[index++] = temp[right++];
                else if (right == rightMax) value[index++] = temp[left++];
                else if (temp[right] < temp[left]) value[index++] = temp[right++];
                else value[index++] = temp[left++];
            }
        }
    }
    delete[] temp;
}



#endif
