//
//  main.cpp
//  Tests
//
//  Created by Edward Costello on 12/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Data.hpp"
#include "Signals.hpp"

using namespace Signals;

TEST_CASE("") {
    auto allocate = [](size_t elementCount) {
        return (double *)calloc(elementCount, sizeof(double));
    };
    
    size_t elementCount = 20;
    double *data = allocate(elementCount);
    auto a = Array<double>(elementCount, data);
    auto v = Vector<double>(elementCount, data);
    v[4] = 445;
    v.print();
    
}


TEST_CASE("") {
    
    Signals::pushContext([](){
        
        //        Object x;
        Scalar y;
        Scalar(54);
        y.i();
    });
    
    Signals::init();
    Signals::tick();
}

