#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#include "GridUtil.h"
#include "SpatialDiscretization.h"
#include "Equations.h"
#include "TimeIntegration.h"

using namespace std;

double initFunction(double x) {
    ///hardcoded function which will provide a good initial condition for now
    ///this can be generalized in the future
    if (x < 0.8) {
        double beta = 0.01;
        double out = exp(-(x-0.4)*(x-0.4) / beta);
        return out;
    } else {
        return 1.0;
    }
}




int main() {
    ///hardcoded inputs
    int nx = 50;
    int iStrut = 1;
    int iDiscr = 1;
    int iEqn_in = 1;
    double a_in = 1.0;
    double xmin = 0.0;
    double xmax = 1.0;
    double cfl = 0.5;


    int mxiter;
    mxiter = 3;//ceil(0.1 * (a_in * (double)nx) / cfl);

    vector<double> x;
    vector<double> dx;
    vector<double> u;
    vector<double> dudt;

    //Generate a 1D grid
    GenerateGrid(iStrut, nx, xmin, xmax, dx, x);

    //Initialize a solution on the grid and create a discretization object
    SpatialDiscretization SD(iDiscr);
    SD.initialize(nx, x, initFunction, u, dudt);

    //Select the desired PDE to solve and give parameters
    EquationSystem PDE(iEqn_in, a_in);


    for (int iter = 0; iter < mxiter; iter++) {
        //Perform Timestep / Update Solution
        ExplicitEuler(nx, cfl, dx, SD, PDE, u);


        //Other Diagnostic / Output stuff

        //Check Convergence
    }

    FILE* fout = fopen("waveout.tec", "w");
    fprintf(fout, "x\tu\n");

    for (int i=0;i<nx;i++){
        fprintf(fout, "%f\t%f\n",x[i], u[i]);
    }
}