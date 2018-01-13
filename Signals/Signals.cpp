//
//  Signals.cpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include "Signals.hpp"

using namespace Signals;

Root root;

void Root::pushContext(function<void()> contextFunction)
{
    contexts.push_back(new Context(contextFunction));
}

void Root::init()
{
    for (auto context : contexts) {
        
        currentContext = context;
        context->init();
    }
    
    root.state = PERF;
}

void Root::tick()
{
    for (auto context : contexts) {
        
        currentContext = context;
        context->tick();
    }
}

void Signals::pushContext(function<void()> contextFunction)
{
    root.pushContext(contextFunction);
}

void Signals::init()
{
    root.init();
}

void Signals::tick()
{
    root.tick();
}

Context *Root::getCurrentContext()
{
    return currentContext;
}

State Root::getState()
{
    return state;
}

void Signals::functionInit(function<void(Context *)> func)
{
    Context *con = root.getCurrentContext();
    
    if (root.getState() == INIT) {
        
        func(con);
    }
}

void Signals::functionTick(function<void(Context *)> func)
{
    Context *con = root.getCurrentContext();
    
    if (root.getState() == PERF) {
        
        func(con);
    }
}

void Signals::functionBoth(function<void(Context *)> func)
{
    Context *con = root.getCurrentContext();
    func(con);
}

void Signals::functionCall(function<void(Context *)> init,
                           function<void(Context *)> both,
                           function<void(Context *)> tick)
{
    Context *con = root.getCurrentContext();
    
    if (root.getState() == INIT) {
        
        init(con);
    }
    
    both(con);
    
    if (root.getState() == PERF) {
        
        tick(con);
    }
}
