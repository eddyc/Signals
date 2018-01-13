//
//  Data.hpp
//  Signals
//
//  Created by Edward Costello on 12/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//


#include <stdio.h>
#include <functional>

using namespace std;
namespace Signals {
   
    template<typename T>
    class Array {
        
    protected:
        const size_t capacity;
        const T *data;
    public:
        
        Array<T>(size_t capacity, T *data);
    };
    
    template<typename T>
    class Vector : public Array<T> {
        
        const size_t stride;
        const size_t elementCount;
    public:
        Vector<T>(size_t elementCount, T *data);
        Vector<T>(size_t elementCount, size_t stride, T *data);
        void print();
        T &operator[](size_t index);
    };
}
