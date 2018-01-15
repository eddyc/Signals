//
//  main.cpp
//  Tests
//
//  Created by Edward Costello on 12/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Data.hpp"
#include "Signals.hpp"

using namespace Signals;


TEST(GeneralTest, GeneralTest) {
    
    auto allocate = [](size_t elementCount) {
        return (double *)calloc(elementCount, sizeof(double));
    };
    
    size_t elementCount = 5;
    double *data = allocate(elementCount);
    auto v = Vector<double>(elementCount, data);
    v[4] = 445;
    double stuff = v[4];
    v.print();
    for (auto &i : v) {
        
        i = 34;
    }
    v.print();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


