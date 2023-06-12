//
// Created by tskoepli on 6/1/2023.
//

#ifndef INC_1D_PDE_SPATIALDISCRETIZATION_H
#define INC_1D_PDE_SPATIALDISCRETIZATION_H

#include <cstdlib>
#include <cstdio>
#include <functional>
#include <vector>
#include "Equations.h"

using namespace std;

struct SpatialDiscretization {
// Contains information of how to get from the underlying solution space to a certain discretized format
    int iDiscr; //specify the method
    int ndegr;  //degrees of freedom per element (= number of values ot store per element)
    int nu;
    int nx;

    explicit SpatialDiscretization(int);

    void initialize(int nx, vector<double>& x, double (&u0Eval)(double), vector<double> &u,  std::vector<double>& dudt);

    void calc_dudt(const vector<double>& dx, const vector<double>& u, const EquationSystem& PDE, vector<double>& dudt);

    void print_sol(vector<double>& x, vector<double>& dx, vector<double>& u, int num);
};

double calc_GhostCell(int iBC, int iSide, double dx, double ui, double value);

#endif //INC_1D_PDE_SPATIALDISCRETIZATION_H
