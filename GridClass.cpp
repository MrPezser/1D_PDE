//
// Created by tskoepli on 5/31/2023.
//

#include <cstdio>
#include "GridClass.h"

GridClass::GridClass(int iStrut, int nx, double xmin, double xmax)
{
    if (iStrut != 1)
    {
        return;
    }

    //x = (double*)malloc(nx*sizeof(double));
    x.reserve(nx);
    dx.push_back((xmax - xmin) / (nx - 1));

    for (int i=0; i<nx; i++){
        x.push_back(xmin + (double)i * dx[0]);

        printf("%d\t%f\n", i, x[i]);
    }

}

GridClass::~GridClass()
{
    x.~vector();
    dx.~vector();

}