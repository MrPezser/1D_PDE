//
// Created by Tsail on 6/1/2023.
//

#include "GridUtil.h"

void GenerateGrid(int iStrut, int nx, double xmin, double xmax, std::vector<double>& dx, std::vector<double>& x)
{
    if (iStrut == 1) {
        //structured grids
        x.reserve(nx);
        dx.reserve(nx);

        double dxa = (xmax - xmin) / (nx - 1);

        for (int i=0; i<nx; i++) {
            dx.push_back(dxa);
            x.push_back(xmin + (double) i * dx[i]);
        }
    }
    return;
}