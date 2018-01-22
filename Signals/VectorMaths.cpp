//
//  VectorMaths.cpp
//  Signals
//
//  Created by Edward Costello on 15/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include "Vector.hpp"
#include <assert.h>

using namespace Signals;

template<typename T>
Vector<T> &Vector<T>::fill(const T input) {
    
    T *data = (T *)this->data;
    for (size_t i = 0; i < this->elementCount; ++i) {
        
        data[i] = input;
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::clear() {
    
    T *data = (T *)this->data;
    memset(data, 0, sizeof(T) * elementCount);
    return *this;
}


template<typename T>
Vector<T> &Vector<T>::multiply(const T input) {
    
    T *data = (T *)this->data;
    for (size_t i = 0; i < this->elementCount; ++i) {
        
        data[i] *= input;
    }
    return *this;
}

template<typename T>
Vector<T> &Vector<T>::add(const T input) {
    
    T *data = (T *)this->data;
    for (size_t i = 0; i < this->elementCount; ++i) {
        
        data[i] += input;
    }
    return *this;
}

template<typename T>
void Vector<T>::add(const Vector<T> &inputA, const Vector<T> &inputB, Vector<T> &output)
{
    assert(inputA.elementCount == inputB.elementCount);
    assert(inputA.elementCount == output.elementCount);
    
    T *outData = (T *)output.data;
    for (size_t i = 0; i < inputA.elementCount; ++i) {
        outData[i] = inputA.data[i] + inputB.data[i];
    }
}

template<typename T>
void Vector<T>::multiply(const Vector<T> &input, const T &scalar, Vector<T> &output)
{
    T *outData = (T *)output.data;
    for (size_t i = 0; i < input.elementCount; ++i) {
        outData[i] = input.data[i] * scalar;
    }
}

template<typename T>
Vector<T> &Vector<T>::ramp(const T start, const T increment) {
    
    T *data = (T *)this->data;
    for (size_t i = 0; i < this->elementCount; ++i) {
        
        data[i] = start + increment * i;
    }
    return *this;
}


template class Signals::Vector<double>;
template class Signals::Vector<float>;
