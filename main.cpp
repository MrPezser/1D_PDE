#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#include "GridClass.h"
#include "SpatialDiscretization.h"

double initFunction(double x) {
    ///hardcoded function which will provide a good initial condition for initial
    /// testing and dev. this should be generalized in the future
    if (x < 0.8) {
        double beta = 0.01;
        return exp(-(x-0.4)*(x-0.4) / beta);
    } else {
        return 1.0;
    }
}

int main() {
    //Generate a 1D grid
    GridClass grid(1, 10, 0.0, 1.0);

    //Initialize a solution on the grid
    SpatialDiscretization FV(1);

    std::vector<double> u = *FV.initialize(grid, &initFunction);


    for (int i=0; i<grid.nx; i++){
        printf("x: %f\tu:%f\n", grid.x[i], u[i]);
    }
}