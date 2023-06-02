//
// Created by tskoepli on 6/1/2023.
//

#ifndef INC_1D_PDE_SPATIALDISCRETIZATION_H
#define INC_1D_PDE_SPATIALDISCRETIZATION_H

#include <cstdlib>
#include <cstdio>
#include <functional>
#include <vector>
using namespace std;

struct SpatialDiscretization {
// Contains information of how to get from the underlying solution space to a certain discretized format
    int iDiscr; //speficy the method
    int ndegr;  //degrees of freedom per element (= number of values ot store per element)
    int nu{};
    int nx{};

    explicit SpatialDiscretization(int);

    void initialize(int nx, vector<double>& x, double (&u0Eval)(double), vector<double> &u);
};


#endif //INC_1D_PDE_SPATIALDISCRETIZATION_H