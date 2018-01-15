//
//  Array.hpp
//  Signals
//
//  Created by Edward Costello on 14/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

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
        Array<T> &operator=(const Array<T> &other);
    };
}
#endif /* Array_hpp */
