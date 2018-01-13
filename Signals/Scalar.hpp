//
//  Scalar.hpp
//  Signals
//
//  Created by Edward Costello on 06/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#ifndef Scalar_hpp
#define Scalar_hpp

#include "Object.hpp"

using namespace Signals;

class ScalarInstance : public ObjectInstance {
    
public:
    int stuff = 54;
    void init();
    void tick();
};

class Scalar : public Object<ScalarInstance> {
    
public:
    Scalar();
    Scalar(int);
};

#endif /* Scalar_hpp */
