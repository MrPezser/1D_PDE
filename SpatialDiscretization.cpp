//
// Created by tskoepli on 6/1/2023.
//


#include "SpatialDiscretization.h"

double calc_GhostCell(int iBC, int iSide, double dx, double ui, double value)  {
    //iSide = 1 is right BC, iSide = -1 if left bc
    if (iBC == 0){
        //Dirichlet boundary Conditions
        return value;
    }
    if (iBC == 1){
        //Neumann boundary condition
        return (ui + (dx*value*(double)iSide));
    }
    return NAN;
}

SpatialDiscretization::SpatialDiscretization(int iDiscr_input) {
    iDiscr = iDiscr_input;


    if (iDiscr == 1){
        //finite volume, 1st order upwind
        ndegr = 1;
        return;
    }
    printf("Invalid discretization operator, change iDiscr.");
}

void SpatialDiscretization::initialize(int nx_in, vector<double>& x, double (&u0Eval)(double), std::vector<double>& u,  std::vector<double>& dudt) {
    //Initialize the solution vector
    nx = nx_in;
    nu = nx * ndegr;
    u.reserve(nu);
    dudt.reserve(nu);

    if (iDiscr == 1){
        //finite volume, use cell center
        for (int i=0; i<nx; i++) {
            u.push_back(u0Eval(x[i]));
        }
    }

}
void SpatialDiscretization::calc_dudt(const vector<double>& dx, const vector<double>& u, const EquationSystem& PDE, vector<double>& dudt)  {

    for (int i=0; i<nu; i++) {
        dudt.push_back(0.0);
    }

    if (iDiscr==1){
        //FV-UP1
        for (int iface=0; iface<(nx+1); iface++){
            //loop through the faces
            double uL, uR, flux;

            if (iface == 0){
                uL = calc_GhostCell(0,-1, dx[0], u[0], u[nx-1]);
                uR = u[0];

                flux = PDE.get_FaceFlux(uL, uR);
                dudt[iface]   += flux / dx[iface];
            }
            if (iface == nx){
                uR = calc_GhostCell(0,-1, dx[0], u[0], u[nx-1]);
                uL = u[nx-1];

                flux = PDE.get_FaceFlux(uL, uR);
                dudt[iface-1] -= flux / dx[iface-1];
               }
            //Get the left and right states
            uL = u[iface-1];
            uR = u[iface];

            //Calculate the flux at the face
            flux = PDE.get_FaceFlux(uL, uR);

            //Add the flux contribution to the RHS
            dudt[iface-1] -= flux / dx[iface-1];
            dudt[iface]   += flux / dx[iface];
        }
        return;
    }
    dudt[0] = NAN;
}

void SpatialDiscretization::print_sol(vector<double>& x, vector<double>& dx ,  vector<double>& u, int num) {
    char title [13];
    sprintf(title, "waveout%3d.tec", num);
    FILE* fout = fopen(title, "w");
    fprintf(fout, "x\tu\n");

    for (int i=0;i<nx;i++){
        fprintf(fout, "%f\t%f\n",x[i]-(0.5*dx[i]), u[i]);
        fprintf(fout, "%f\t%f\n",x[i]+(0.5*dx[i]), u[i]);
    }
}