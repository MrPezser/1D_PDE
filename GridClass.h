//
// Created by tskoepli on 5/31/2023.
//

#include <vector>

#ifndef INC_1D_PDE_GRIDCLASS_H
#define INC_1D_PDE_GRIDCLASS_H


class GridClass {

    public:

    std::vector<double> x;
    std::vector<double> dx;
    int iStruct{};
    int nx{};

    GridClass(int iStrut, int nx, double xmin, double xmax);
    ~GridClass();
};


#endif //INC_1D_PDE_GRIDCLASS_H
