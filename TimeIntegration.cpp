//
// Created by Tsail on 6/2/2023.
//

#include "TimeIntegration.h"

void CalcDt(const double cfl,const vector<double>& dx,const EquationSystem& PDE , double &dt) {
    dt = cfl * (*min_element(dx.begin(), dx.end())) / PDE.get_MaxCharSpeed();
}

double ExplicitEuler(const int nx, const double cfl, vector<double>& dx, SpatialDiscretization& SD , EquationSystem& PDE, vector<double>& u) {
    double dt = 0.0;
    vector<double> dudt;
    dudt.reserve(SD.nu);

    //Find timestep
    CalcDt(cfl, dx, PDE, dt);

    //Find the derivative w.r.t time based on current state
    SD.calc_dudt(dx, u, PDE, dudt);

    //Perform Explicit Euler Step
    for(int i=0; i<SD.nu; i++){
        u[i] += dt*dudt[i];
    }

    return dt;
}
