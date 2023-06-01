//
// Created by tskoepli on 5/31/2023.
//

#include <cstdio>
#include "GridClass.h"

GridClass::GridClass(int iStrut, int num_x, double xmin, double xmax)
{
    if (iStrut != 1) { return; }
    nx = num_x;
    //x = (double*)malloc(nx*sizeof(double));
    x.reserve(nx);
    dx.push_back((xmax - xmin) / (nx - 1));

    for (int i=0; i<nx; i++){
        x[i] = xmin + (double)i * dx[0];
    }

}

GridClass::~GridClass()
{
   // x.~vector();
   // dx.~vector();

}