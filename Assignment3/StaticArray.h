// Programmer: Aurelia Kisanaga
// Programmer's ID: 1960007

#ifndef STATICARRAY_H
#define STATICARRAY_H
using namespace std;

template <typename T, int CAP>
class StaticArray
{
    T value[CAP]; // T datatype CAP compasity
    T dummy;

public:
    StaticArray();
    int capacity() const;
    T operator[] (int) const; // getter
    T& operator[] (int); // setter
};

// Main Constructor
template<typename T, int CAP>
StaticArray<T, CAP>::StaticArray()
{
    for (int i = 0; i < CAP; i++)
        value[i] = T();
    dummy = T();
}

// Capacity
template <typename T, int CAP>
int StaticArray<T, CAP>::capacity() const { return CAP; }

// getter
template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const
{
    if (index < 0) return dummy;
    if (index >= CAP) return dummy;
    return value[index];
}

// setter
template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index)
{
    if (index < 0) return dummy;
    if (index >= CAP) return dummy;
    return value[index];
}

#endif 
