#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#include "GridUtil.h"
#include "SpatialDiscretization.h"
#include "Equations.h"
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

void CalcDt(double cfl, vector<double>& dx, EquationSystem PDE , double &dt) {
    dt = cfl * (*min_element(dx.begin(), dx.end())) / PDE.get_MaxCharSpeed();
}

int main() {
    ///hardcoded inputs
    int nx = 15;
    int iStrut = 1;
    int iDiscr = 1;
    int mxiter = 100;
    int iEqn_in = 1;
    double a_in = 1.0;
    double xmin = 0.0;
    double xmax = 1.0;
    double cfl = 0.5;

    double dt;
    vector<double> x;
    vector<double> dx;
    vector<double> u;
    vector<double> dudt;

    //Generate a 1D grid
    GenerateGrid(iStrut, nx, xmin, xmax, dx, x);

    //Initialize a solution on the grid and create a discretization object
    SpatialDiscretization FV(iDiscr);
    FV.initialize(nx, x, initFunction, u);

    //Select the desired PDE to solve and give parameters
    EquationSystem PDE(iEqn_in, a_in);


    for (int iter = 0; iter < mxiter; iter++) {
        //Calculate Timestep ~~ dt = cfl * dx / a
        CalcDt(cfl, dx, PDE, dt);
        //Calculate Solution update

        //Update Solution / Perform Iteration

        //Compute Residual

        //Other Diagnostic / Output stuff
        printf("dt:%f\n", dt);
        //Check Convergence
    }
}