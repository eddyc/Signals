//
//  Object.hpp
//  Signals
//
//  Created by Edward Costello on 22/12/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <functional>
using namespace std;
namespace Signals {
    
    class ObjectInstance {
        
    public:
       
        ObjectInstance();
        virtual void init();
        virtual void tick();
    };
   
    template <class T>
    class Object {
       
        T *instance;
        size_t instanceNumber;

    public:
        function<void()> i;
        Object();
    };
}

#endif /* Object_hpp */
