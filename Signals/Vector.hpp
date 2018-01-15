//
//  Vector.hpp
//  Signals
//
//  Created by Edward Costello on 14/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <functional>
#include "Array.hpp"

using namespace std;
namespace Signals {

    template<typename T>
    class Vector : public Array<T> {
        
        const size_t stride;
        const size_t elementCount;
    public:
        
        T *begin();
        T *end();
        const T *cbegin() const;
        const T *cend() const;
        const T *begin() const;
        const T *end() const;

        Vector<T>();
        Vector<T>(const Vector<T> &other);
        Vector<T>(size_t elementCount, T *data);
        Vector<T>(size_t elementCount, size_t stride, T *data);
        void print();
        T &operator[](size_t index);
        Vector<T> &operator=(Vector<T> &&other);
    };
}

#endif /* Vector_hpp */
