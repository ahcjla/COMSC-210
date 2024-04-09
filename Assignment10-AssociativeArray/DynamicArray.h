// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#ifndef LABEXERCISE4_H
#define LABEXERCISE4_H

template<typename T>
class DynamicArray
{
    T* value;   // T datatype CAP compasity
    int cap;
    T dummy = T();

public:
    DynamicArray(int = 2);  // constructor // default = 2
    DynamicArray(const DynamicArray<T>&);   // copy constructor
    ~DynamicArray() { delete[] value; }    // destructor
    DynamicArray<T>& operator = (const DynamicArray<T>&);   // assignment operator 
    int capacity() const;
    void capacity(int);     // setter
    T operator[] (int) const;   // getter
    T& operator[] (int);    // setter
};

// Constructor
template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
    this->cap = cap;
    value = new T[cap];
    for (int i = 0; i < cap; i++)
        value[i] = T();
}

// Copy Constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
    cap = original.cap;
    value = new T[cap];
    for (int i = 0; i < cap; i++)
        value[i] = original.value[i];
    dummy = original.dummy;
}


// Assignment Operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray<T>& original)
{
    if (this != &original)
    {
        delete[] value;
        cap = original.cap;
        value = new T[cap];
        for (int i = 0; i < cap; i++)
            value[i] = original.value[i];
        dummy = original.dummy;
    }
    return *this;
}

// Getter Capacity
template <typename T>
int DynamicArray<T>::capacity() const { return cap; }

// Setter Capacity
template <typename T>
void DynamicArray<T>::capacity(int cap)
{
    T* temp = new T[cap];
    int limit = (cap < this->cap ? cap : this->cap);
    for (int i = 0; i < limit; i++)
        temp[i] = value[i];
    for (int i = limit; i < cap; i++)
        temp[i] = T();
    delete[] value;
    value = temp;
    this->cap = cap;
}

// Getter
template <typename T>
T DynamicArray<T>::operator[](int index) const
{
    if (index < cap && index > -1) return value[index];
    return dummy;
}

// Setter
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
    if (index < 0) return dummy;
    if (index >= cap) capacity(2 * index);
    return value[index];
}

#endif
