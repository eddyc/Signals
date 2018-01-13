//
//  Context.hpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#ifndef Context_hpp
#define Context_hpp

#include <stdio.h>
#include <functional>
#include <vector>
//#include "Stream.hpp"
namespace Signals {
    
    using namespace std;
//    class Context {
//
//        function<void()> operation;
//        vector<StreamInstance *> streamInstances;
//        size_t streamIndex = 0;
//
//    public:
//        Context(function<void()>);
//        void pushStream();
//        StreamInstance *getNextStream();
//        void init();
//        void tick();
//    };
    
    class ObjectInstance;
    class Context {
       
        function<void()> operation;
        vector<ObjectInstance *> objectInstances;
    public:
        size_t objectCount = 0;
        Context(function<void()> operation);
        template<class T>
        T *pushObject();
        template<class T>
        T *getObject(int);
        void init();
        void tick();
    };
}
#endif /* Context_hpp */

