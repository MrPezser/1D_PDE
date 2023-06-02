//
// Created by Tsail on 6/1/2023.
//

#ifndef INC_1D_PDE_GRIDUTIL_H
#define INC_1D_PDE_GRIDUTIL_H

#include <vector>

void GenerateGrid(int iStrut, int nx, double xmin, double xmax, std::vector<double>& dx, std::vector<double>& x);

#endif //INC_1D_PDE_GRIDUTIL_H
