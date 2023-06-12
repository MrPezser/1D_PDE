//
// Created by Tsail on 6/1/2023.
//

#ifndef INC_1D_PDE_EQUATIONS_H
#define INC_1D_PDE_EQUATIONS_H

#include <vector>
#include <cstdlib>
#include <cmath>

struct EquationSystem {

    int iEqn;

    EquationSystem(int iEqn_in, double a);

    double get_MaxCharSpeed() const;
    double get_FaceFlux(double d, double d1) const;

private:
    //general variable that can be used differently for different equations
    double v1;

};


#endif //INC_1D_PDE_EQUATIONS_H
