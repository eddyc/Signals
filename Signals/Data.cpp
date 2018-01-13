//
//  Data.cpp
//  Signals
//
//  Created by Edward Costello on 12/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include "Data.hpp"
#include <iostream>
#include <assert.h>
using namespace std;
using namespace Signals;

template <typename T>
Array<T>::Array(size_t capacity, T *data) :
capacity(capacity),
data(data)
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

template class Signals::Array<double>;
template class Signals::Array<float>;
template class Signals::Vector<double>;
template class Signals::Vector<float>;
