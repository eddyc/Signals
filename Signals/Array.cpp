//
//  Array.cpp
//  Signals
//
//  Created by Edward Costello on 14/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include "Array.hpp"
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
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    
    return *this;
}
template class Signals::Array<double>;
template class Signals::Array<float>;
