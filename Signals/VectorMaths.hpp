//
//  VectorMaths.hpp
//  Signals
//
//  Created by Edward Costello on 15/01/2018.
//  Copyright © 2018 Edward Costello. All rights reserved.
//

#ifndef VectorMaths_hpp
#define VectorMaths_hpp

Vector<T> &fill(const T);
Vector<T> &clear();
Vector<T> &multiply(const T);
Vector<T> &add(const T);
static void add(const Vector<T> &inputA, const Vector<T> &inputB, Vector<T> &output);
static void multiply(const Vector<T> &input, const T &scalar, Vector<T> &output);
Vector<T> &ramp(const T start, const T increment);

#endif /* VectorMaths_hpp */
