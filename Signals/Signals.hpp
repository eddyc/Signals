//
//  Signals.hpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#ifndef Signals_hpp
#define Signals_hpp

#include "Context.hpp"
#include "Stream.hpp"
#include "Object.hpp"
#include "Scalar.hpp"
#include <vector>
#include <functional>

using namespace std;

namespace Signals {
    
    typedef enum {
        INIT,
        PERF
    } State;
    
    class Root {
        
        State state = INIT;
        
        vector<Context *> contexts;
        Context *currentContext;
        
    public:
        void pushContext(function<void()>);
        Context *getCurrentContext();
        State getState();
        void init();
        void tick();
    };
    
    
    void init();
    void tick();
    void pushContext(function<void()>);
    void functionInit(function<void(Context *)>);
    void functionTick(function<void(Context *)>);
    void functionBoth(function<void(Context *)>);
    void functionCall(function<void(Context *)>, function<void(Context *)>, function<void(Context *)>);
}

#endif /* Signals_hpp */
