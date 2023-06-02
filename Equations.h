//
// Created by Tsail on 6/1/2023.
//

#ifndef INC_1D_PDE_EQUATIONS_H
#define INC_1D_PDE_EQUATIONS_H

#include <vector>

struct EquationSystem {

    int iEqn;

    EquationSystem(int iEqn_in, double a);
    double get_MaxCharSpeed();

    private:
    //general variable that can be used differently for different equations
    double v1;

};


#endif //INC_1D_PDE_EQUATIONS_H
