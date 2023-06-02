//
// Created by Tsail on 6/1/2023.
//

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

double EquationSystem::get_FaceFlux(double uLeft, double uRight) {

    if (iEqn ==1) {
        if (v1 > 0){
            return v1 * uLeft;
        } else {
            return v1 * uRight;
        }
    }
    return NAN;
}
