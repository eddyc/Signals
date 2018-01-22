//
//  main.cpp
//  Signals
//
//  Created by Edward Costello on 23/11/2017.
//  Copyright © 2017 Edward Costello. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "FileIO.hpp"


class ScaledSymmetricSigmaPoints;

using namespace Signals;

auto allocateVector = [](size_t elementCount) -> tuple<double *, size_t> {
    return {
        (double *)calloc(elementCount, sizeof(double)),
        elementCount
    };
};

auto allocateMatrix = [](size_t rowCount, size_t columnCount) -> tuple<double *, size_t, size_t> {
    return {
        (double *)calloc(rowCount * columnCount, sizeof(double)),
        rowCount,
        columnCount
    };
};

struct ScaledSymmetricSigmaPoints
{
    Matrix<double> p, xPts;
    Vector<double>wPts;
    size_t nsp;
    ScaledSymmetricSigmaPoints(size_t p) :
    p(allocateMatrix(p * 2 + 1, p * 2 + 1)),
    wPts(allocateVector((p + 1) * 4)),
    xPts(allocateMatrix(p * 2 + 1, (p * 2 + 1) * 2 + 1))
    {}
    
    auto operator()(const Vector<double> &x, const Matrix<double> &pIn,
                    const double alpha, const double beta, double kappa) {
        
        Matrix<double>::copy(pIn, p);
        double n = x.elementCount;
        nsp = 2 * n + 1;
        p.multiply(n + kappa);
        p.choleskyFactorisation();
        Matrix<double>::copy(p, xPts.subMatrix(p.rowCount, 0, p.columnCount, p.columnCount + 1));
        p.multiply(-1);
        Matrix<double>::copy(p, xPts.subMatrix(p.rowCount, 0, p.columnCount, 1));
        
        for (size_t i = 0; i < xPts.rowCount; ++i) {
            
            double &s = ((Vector<double> &)x)[i];
            xPts[i][0] = 0;
            xPts[i].add(s);
        }
        
        wPts.fill(0.5);
        wPts[0] = kappa;
        wPts.multiply(1/(n+kappa));
        wPts.last() =  wPts[0] + (1 - pow(alpha, 2)) + beta;
        
        return make_tuple(xPts, wPts, nsp);
    }
};

int main(int argc, const char * argv[]) {
    
    Vector<double> input;
    FileIO::openDataset("input.h5",
                        "input",
                        allocateMatrix,
                        [&input](double *data, size_t rowCount, size_t columnCount) {
                            input = Vector<double>(data, rowCount * columnCount);
                        });
    
    double p = 8;
    double alpha = 1;
    double beta = 0;
    double kappa = 2;
//    double states = p;
    double vNoise = p;
    double wNoise = 1;
    double noises = vNoise + wNoise;
//    double observations = 1;
    
    ScaledSymmetricSigmaPoints scaledSymmetricSigmaPts(p);
    
    double M = p / 2;
    double observations = 1;
    Vector<double> xhat({300., 2200., 3000., 3500., 20., 20., 20., 20.});
    auto Qw = Matrix<double>(allocateMatrix(p, p));
    Qw.identity().multiply(50);
    
    auto Pcov = Matrix<double>(allocateMatrix(p, p));
//    auto N = Matrix<double>(allocateMatrix(p + 1, p + 1));
    auto PQ = Matrix<double>(allocateMatrix(p * 2 + 1, p * 2 + 1));
    auto xQ = Vector<double>(allocateVector(p + noises));
    auto wSigmaPts_xmat = Matrix<double>(allocateMatrix(xQ.elementCount * 2, xQ.elementCount * 2));
    auto wSigmaPts_zmat = Matrix<double>(allocateMatrix(observations, xQ.elementCount * 2));
    auto xEst = Vector<double>(allocateVector(p));
    Vector<double>::copy(xhat, xEst);
    Pcov.diagonal().fill(100);
    PQ.diagonal().subVector(p, p).fill(50);
    PQ.last() = 0.1;
    
    for (size_t k = 2 * M; k < input.elementCount; ++k) {
        
        Matrix<double>::copy(Pcov, PQ.subMatrix(p, 0, p, 0));
        Vector<double>::copy(xEst, xQ.subVector(0, xEst.elementCount));
        
        auto [xSigmaPts, wSigmaPts, nsp] = scaledSymmetricSigmaPts(xQ, PQ, alpha, beta, kappa);
        
        wSigmaPts_xmat.repeatRows(wSigmaPts.subVector(1, wSigmaPts.elementCount - 2));
        Vector<double>::copy(wSigmaPts.subVector(1, wSigmaPts.elementCount - 2), wSigmaPts_zmat);
        wSigmaPts_zmat.print();
        
        
    }
    
    return 0;
}


