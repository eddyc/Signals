//
//  main.cpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
#include "FileIO.hpp"

using namespace Signals;
int main(int argc, const char * argv[]) {
   
    auto allocate = [](size_t elementCount) {
        return (double *)calloc(elementCount, sizeof(double));
    };
    
    Vector<double> input;
    FileIO::openDataset("/Volumes/Data/GoogleDrive/PhD/Thesis/Chapters/FormantTracking/Tests/TestUKFFormant/input.h5", "input",
                        allocate,
                        [&input](double *data, size_t rowCount, size_t columnCount) {
        
        input = Vector<double>(rowCount * columnCount, data);
        cout << rowCount << " " << columnCount << endl;
    });
    

    
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
    return 0;
}
