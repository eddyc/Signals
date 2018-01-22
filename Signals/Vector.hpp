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

using namespace std;
namespace Signals {

    template<typename T>
    class Vector {
    public:
        
        const T *data;
        const size_t elementCount;
        
        T &last();
        T *begin();
        T *end();
        const T *cbegin() const;
        const T *cend() const;
        const T *begin() const;
        const T *end() const;

        Vector<T>();
        Vector<T>(const Vector<T> &other);
        Vector<T>(T *data, size_t elementCount);
        Vector<T>(tuple<T *, size_t>);
        Vector<T>(initializer_list<T>);
        Vector<T>(pair<T *, size_t>);
        static void copy(const Vector<T>, Vector<T>);
        Vector<T> subVector(size_t offset, size_t elementCount);
        
        void print();
        T &operator[](size_t index);
        Vector<T> &operator=(Vector<T> &&other);

#include "VectorMaths.hpp"
    };
    
    template<typename T>
    class StridedVector {
    public:
        
        const T *data;
        const size_t capacity;
        const size_t elementCount;
        const size_t stride;
        
        StridedVector<T>(T *data, size_t capacity, size_t elementCount, size_t stride);
        StridedVector<T> subVector(size_t elementCount, size_t offset);
        void print();
        void printAll();
        T &operator[](size_t index);
        StridedVector<T> &operator=(StridedVector<T> &&other);
        
        
#include "StridedVectorMaths.hpp"
    };

}

#endif /* Vector_hpp */
