//
// Created by Tsail on 6/1/2023.
//

#include <cstdlib>
#include "Equations.h"

EquationSystem::EquationSystem(int iEqn_in, double a) {
    //Constructor for the 1D Advection Equation
    if (iEqn_in != 1) {abort();}
    iEqn = 1;
    v1 = a; //For the advection equation v1 is the wave speed
}

double EquationSystem::get_MaxCharSpeed() {
    switch (iEqn) {
        case 1 : return v1;

    }
}
