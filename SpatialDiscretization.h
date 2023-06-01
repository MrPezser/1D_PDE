//
// Created by tskoepli on 6/1/2023.
//

#ifndef INC_1D_PDE_SPATIALDISCRETIZATION_H
#define INC_1D_PDE_SPATIALDISCRETIZATION_H

#include <cstdlib>
#include <cstdio>
#include <functional>
#include <vector>
#include "GridClass.h"

class SpatialDiscretization {
// Contains information of how to get from the underlying solution space to a certain discretized format

    public:

    int iDiscr; //speficy the method
    int ndegr;  //degrees of freedom per element (= number of values ot store per element)

    explicit SpatialDiscretization(int);

    std::vector<double> *initialize(GridClass grid, const std::function<double(double)> &u0Eval);
};


#endif //INC_1D_PDE_SPATIALDISCRETIZATION_H
