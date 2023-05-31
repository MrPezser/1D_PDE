#include <iostream>
#include <cstdio>
#include "GridClass.h"
#include <vector>


int main() {
    auto grid = new GridClass(1, 10, 0.0, 1.0);

    //std::vector<double> x = grid.x;
    int nx = grid->nx;

    printf("Generated uniform grid from %f to %f using %d elements.\n",\
    grid->x[0], grid->x[nx], nx);

}
