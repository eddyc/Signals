//
//  Object.cpp
//  Signals
//
//  Created by Edward Costello on 22/12/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include "Object.hpp"
#include "Signals.hpp"

using namespace Signals;

ObjectInstance::ObjectInstance()
{
    
}

void ObjectInstance::init()
{
    printf("initting\n");
}

void ObjectInstance::tick()
{
    printf("tikking\n");
}

function<void()> blank = []() {
   
    printf("blank");
};

template <class T>
Object<T>::Object() {
    
    auto init = [this](Context *con) {
        
        this->instance = con->pushObject<T>();
        instanceNumber = con->objectCount;
        con->objectCount++;
        this->i = std::bind(&T::init, this->instance);
    };
    
    auto both = [this](Context *con) {
        
        this->instance = con->getObject<T>(instanceNumber);
        this->i = std::bind(&T::init, this->instance);
        //            this->k.self = this;
    };
    
    auto tick = [this](Context *con) {
        this->instance->tick();
    };
    
    functionCall(init, both, tick);
}


template class Signals::Object<ScalarInstance>;
