//
//  MatrixMaths.cpp
//  Signals
//
//  Created by Edward Costello on 15/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include "Matrix.hpp"
#include <math.h>

using namespace Signals;

template<typename T>
Matrix<T> &Matrix<T>::identity() {
   
    for (size_t i = 0; i < rowCount; ++i) {
        
        (*this)[i][i] = 1;
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::choleskyFactorisation() {
    
    auto divide = [](T *data, T scalar, size_t stride, size_t elementCount) {
        
        for (size_t i = 0; i < elementCount; ++i) {
            data[i * stride] /= scalar;
        }
    };
    
    for (size_t i = 0; i < rowCount; ++i) {
        

        (*this)[i][i] = sqrt((*this)[i][i]);
        (*this)[i].subVector(i + 1, rowCount - i - 1).clear();
        T *data = (T *)this->data;

        divide((T *)&data[((i + 1) * columnCount) + i],
               (*this)[i][i], columnCount,
               (size_t)(rowCount - i - 1));

        for (size_t j = i + 1; j < rowCount; ++j) {
            
            for (size_t k = 0; k < rowCount - i - 1; ++k) {
                
                T scalar = (*this)[j][i];
                Vector<T> vec = (*this)[i + 1];
                T *data = (T *)vec.data;
                scalar *= data[i + k * columnCount];
                data[j + k * columnCount] -= scalar;
            }
        }
    }
    return *this;
}


template class Signals::Matrix<double>;
template class Signals::Matrix<float>;
