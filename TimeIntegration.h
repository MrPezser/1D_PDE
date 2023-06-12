//
// Created by Tsail on 6/2/2023.
//

#ifndef INC_1D_PDE_TIMEINTEGRATION_H
#define INC_1D_PDE_TIMEINTEGRATION_H

#include <vector>
#include <algorithm>
#include "Equations.h"
#include "SpatialDiscretization.h"

using namespace std;

double ExplicitEuler(int nx, double cfl, vector<double>& dx, SpatialDiscretization& SD , EquationSystem& PDE, vector<double>& u);

#endif //INC_1D_PDE_TIMEINTEGRATION_H
