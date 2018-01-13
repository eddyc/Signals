//
//  Context.cpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include "Context.hpp"
#include "Object.hpp"
#include "Scalar.hpp"

using namespace Signals;

//Context::Context(function<void()> operation)
//{
//    this->operation = operation;
//}
//
//void Context::init()
//{
//    operation();
//}
//
//void Context::tick()
//{
//    streamIndex = 0;
//    operation();
//}
//
//void Context::pushStream()
//{
//    streamInstances.push_back(new StreamInstance(256));
//}
//
//StreamInstance *Context::getNextStream()
//{
//    size_t index = streamIndex;
//    streamIndex++;
//    return streamInstances[index];
//}

Context::Context(function<void()> operation)
{
    this->operation = operation;
}

void Context::init()
{
    operation();
}

void Context::tick()
{
    operation();
}

template<class T>
T *Context::pushObject()
{
    T *self = new T();
    objectInstances.push_back(self);
    return self;
}

template<class T>
T *Context::getObject(int index)
{
    return (T *)objectInstances[index];
}

template ScalarInstance *Context::pushObject<ScalarInstance>();
template ScalarInstance *Context::getObject<ScalarInstance>(int);
