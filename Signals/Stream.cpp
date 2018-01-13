//
//  Stream.cpp
//  Signals
//
//  Created by Edward Costello on 24/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include "Stream.hpp"
#include "Signals.hpp"

using namespace Signals;

//StreamInstance::StreamInstance(size_t elementCount)
//{
//    data = new double[elementCount]();
//    this->elementCount = elementCount;
//}
//
//StreamInstance::~StreamInstance()
//{
//    delete [] data;
//}
//
//Stream::Stream(_StackStream s) : instance(0){
//    i.self = 0;
//    k.self = 0;
//}
//
//Stream::Stream()
//{
//    auto init = [this](Context *con) {
//        
//        con->pushStream();
//        printf("init\n");
//    };
//    
//    auto both = [this](Context *con) {
//        
//        this->instance = con->getNextStream();
//        this->i.self = this;
//        this->k.self = this;
//    };
//    
//    auto tick = [this](Context *con) {
//        
//    };
//    
//    functionCall(init, both, tick);
//}
//
//
//Stream Signals::operator+(const Stream &left, const Stream &right)
//{
//    Stream self(StackStream);
//    
//    auto init = [self](Context *con) {
//        con->pushStream();
//    };
//    
//    auto both = [&self, left, right](Context *con) {
//        self.instance = con->getNextStream();
//        self.i.self = &self;
//        self.k.self = &self;
//        
//        for (int i = 0; i < self.instance->elementCount; ++i) {
//            self.instance->data[i] = left.instance->data[i] + right.instance->data[i];
//        }
//    };
//    
//    auto tick = [&self, left, right](Context *con) {
//        
//    };
//    
//    functionCall(init, both, tick);
//    return self;
//}
//
//Stream Stream::operator=(Stream &right)
//{
//    Stream self(StackStream);
//    return self;
//}
//
//
//Stream &Stream::StreamInit::fill(double n)
//{
//    for (int i = 0; i < self->instance->elementCount; ++i) {
//        
//        self->instance->data[i] = n;
//    }
//    return *self;
//}
//
//void Stream::print()
//{
//    for (int i = 0; i < this->instance->elementCount; ++i) {
//        
//        printf("[%f]", this->instance->data[i]);
//    }
//}

