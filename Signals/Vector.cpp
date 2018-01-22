//
//  Vector.cpp
//  Signals
//
//  Created by Edward Costello on 14/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "Vector.hpp"
using namespace std;
using namespace Signals;

template<typename T>
Vector<T>::Vector(const Vector<T> &other) :
data(other.data),
elementCount(other.elementCount)
{}

template <typename T>
Vector<T>::Vector() :
data(nullptr),
elementCount(0)
{}

template <typename T>
Vector<T>::Vector(tuple<T *, size_t> t) :
data(get<0>(t)),
elementCount(get<1>(t))
{}

template <typename T>
Vector<T>::Vector(T *data, size_t elementCount) :
data(data),
elementCount(elementCount)
{}

template <typename T>
Vector<T>::Vector(pair<T *, size_t> p) :
data(p.first),
elementCount(p.second)
{}

template <typename T>
Vector<T>::Vector(initializer_list<T> data) :
data(data.begin()),
elementCount(data.size())
{}


template <typename T>
void Vector<T>::copy(const Vector<T> source, Vector<T> destination)
{
    assert(source.elementCount == destination.elementCount);
    memcpy((void *)destination.data, (const void *)source.data, source.elementCount * sizeof(T));
}

template<typename T>
Vector<T> Vector<T>::subVector(size_t offset, size_t elementCount)
{
    assert(elementCount + offset <= this->elementCount);
    
    return Vector<T>((T *)&data[offset], elementCount);
}



template <typename T>
void Vector<T>::print()
{
    for (size_t i = 0; i < elementCount; ++i) {
        
        cout << "[" << (*this)[i] << "]";
    }
    cout << endl;
}

template <typename T>
T &Vector<T>::operator[](size_t index)
{
    assert(index < elementCount);
    T *data = (T *)this->data;
    return data[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other)
{
    if (this != &other) {
        memcpy((void *)&data, &other.data, sizeof(T *));
        memcpy((void *)&elementCount, (void *)&other.elementCount, sizeof(size_t));
    }
    return *this;
}

template <typename T>
T &Vector<T>::last() {
    
    return *(T *)&this->data[elementCount - 1];
}

template <typename T>
T *Vector<T>::begin() {
    
    return (T *)this->data;
}

template <typename T>
T *Vector<T>::end()
{
    
    return (T *)((char *)this->data + elementCount * sizeof(T));
}

template <typename T>
const T *Vector<T>::cbegin() const
{
    return (const T *)this->data;
}

template <typename T>
const T *Vector<T>::cend() const
{
    return (const T *)((char *)this->data + elementCount * sizeof(T));
}

template <typename T>
const T *Vector<T>::begin() const
{
    return (const T *)this->data;
}

template <typename T>
const T *Vector<T>::end() const
{
    return (const T *)((char *)this->data + elementCount * sizeof(T));
}

template<typename T>
StridedVector<T>::StridedVector(T *data, size_t capacity, size_t elementCount, size_t stride) :
data(data),
capacity(capacity),
elementCount(elementCount),
stride(stride)
{
    assert(((elementCount - 1) * stride) + 1 <= capacity);
}

template<typename T>
StridedVector<T> StridedVector<T>::subVector(size_t elementCount, size_t offset)
{
    assert(elementCount + offset <= this->elementCount);
    
    return StridedVector<T>((T *)&data[offset * stride], capacity - offset * stride, elementCount, stride);
}


template <typename T>
T &StridedVector<T>::operator[](size_t index)
{
    assert(index < elementCount);
    T *data = (T *)this->data;
    return data[index * stride];
}

template <typename T>
void StridedVector<T>::print()
{
    for (size_t i = 0; i < elementCount; ++i) {
        
        cout << "[" << (*this)[i] << "]";
    }
    cout << endl;
}

template <typename T>
void StridedVector<T>::printAll()
{
    for (size_t i = 0; i < capacity; ++i) {
        
        cout << "[" << this->data[i] << "]";
    }
    cout << endl;
}


template class Signals::Vector<double>;
template class Signals::Vector<float>;
template class Signals::StridedVector<double>;
template class Signals::StridedVector<float>;
