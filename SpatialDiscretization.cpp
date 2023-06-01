//
// Created by tskoepli on 6/1/2023.
//


#include "SpatialDiscretization.h"

SpatialDiscretization::SpatialDiscretization(int iDiscr_input) {
    iDiscr = iDiscr_input;


    if (iDiscr == 1){
        //finite volume
        ndegr = 1;
    }
    printf("Invalid discretization operator, change iDiscr.");
}

std::vector<double> * SpatialDiscretization::initialize(GridClass grid, const std::function<double(double)>& u0Eval) {
    //Initialize the solution vector
    int nu = grid.nx * ndegr;
    auto u = new std::vector<double>;
    (*u).reserve(nu);

    if (iDiscr == 1){
        //finite volume, use cell center
        for (int i=0; i<grid.nx; i++) {
            (*u)[i] = u0Eval(grid.x[i]);
        }
    }

    return u;
}
