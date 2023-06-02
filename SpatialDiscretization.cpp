//
// Created by tskoepli on 6/1/2023.
//


#include "SpatialDiscretization.h"

SpatialDiscretization::SpatialDiscretization(int iDiscr_input) {
    iDiscr = iDiscr_input;


    if (iDiscr == 1){
        //finite volume
        ndegr = 1;
        return;
    }
    printf("Invalid discretization operator, change iDiscr.");
}

void SpatialDiscretization::initialize(int nx_in, vector<double>& x, double (&u0Eval)(double), std::vector<double>& u) {
    //Initialize the solution vector
    nx = nx_in;
    nu = nx * ndegr;
    u.reserve(nu);

    if (iDiscr == 1){
        //finite volume, use cell center
        for (int i=0; i<nx; i++) {
            u[i] = u0Eval(x[i]);
        }
    }

}
