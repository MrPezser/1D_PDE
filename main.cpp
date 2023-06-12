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
    double cfl = 0.75;
    double tmax = 1.0;


    int mxiter;
    mxiter = 65;

    vector<double> x;
    vector<double> dx;
    vector<double> u;
    vector<double> dudt;
    double dt;
    double t = 0.0;

    //Generate a 1D grid
    printf("Generating Grid\n");
    GenerateGrid(iStrut, nx, xmin, xmax, dx, x);

    printf("initializing Solution\n");
    //Initialize a solution on the grid and create a discretization object
    SpatialDiscretization SD(iDiscr);
    SD.initialize(nx, x, initFunction, u, dudt);

    printf("Initializing Equation Object\n");
    //Select the desired PDE to solve and give parameters
    EquationSystem PDE(iEqn_in, a_in);


    printf("Beginning Loop\n");
    for (int iter = 0; iter < mxiter; iter++) {
        //Perform Timestep / Update Solution
        dt = ExplicitEuler(nx, cfl, dx, SD, PDE, u);
        t += dt;

        //Other Diagnostic / Output stuff

        //Check Convergence
        if (t >= tmax) {break;}
    }

    printf("Printing Out Solution\n");
    SD.print_sol(x, dx, u, 1);

    /*
    FILE* fout = fopen("waveout.tec", "w");
    fprintf(fout, "x\tu\n");

    for (int i=0;i<nx;i++){
        fprintf(fout, "%f\t%f\n",x[i], u[i]);
    }*/
}