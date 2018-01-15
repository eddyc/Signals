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

template <typename T>
Vector<T>::Vector() :
Array<T>(0, nullptr),
elementCount(0),
stride(0)
{}

template <typename T>
Vector<T>::Vector(size_t elementCount, T *data) :
Array<T>(elementCount, data),
elementCount(elementCount),
stride(1)
{}


template <typename T>
Vector<T>::Vector(size_t elementCount, size_t stride, T *data) :
Array<T>(elementCount, data),
elementCount(elementCount),
stride(stride)
{}

template <typename T>
void Vector<T>::print()
{
    for (size_t i = 0; i < elementCount; ++i) {
        
        cout << this->data[i] << endl;
    }
}

template <typename T>
T &Vector<T>::operator[](size_t index)
{
    assert(index * stride < elementCount);
    T *data = (T *)this->data;
    return data[index * stride];
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other)
{
    if (this != &other) {
        memcpy((void *)&this->data, &other.data, sizeof(T *));
        memcpy((void *)&this->capacity, (void *)&other.capacity, sizeof(size_t));
        memcpy((void *)&elementCount, (void *)&other.elementCount, sizeof(size_t));
        memcpy((void *)&stride, &other.stride, sizeof(int));
    }
    return *this;
}

template <typename T>
T *Vector<T>::begin() {
    
    return (T *)this->data;
}

template <typename T>
T *Vector<T>::end() { return (T *)((char *)this->data + (elementCount * stride) * sizeof(T)); }

template <typename T>
const T *Vector<T>::cbegin() const
{
    return (const T *)this->data;
}

template <typename T>
const T *Vector<T>::cend() const
{
    return (const T *)((char *)this->data + (elementCount * stride) * sizeof(T));
}

template <typename T>
const T *Vector<T>::begin() const
{
    return (const T *)this->data;
}

template <typename T>
const T *Vector<T>::end() const
{
    return (const T *)((char *)this->data + (elementCount * stride) * sizeof(T));
}

template class Signals::Vector<double>;
template class Signals::Vector<float>;
