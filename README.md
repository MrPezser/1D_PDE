# 1D_PDE

[State of Project: Finite Volume of Advection Equation]
[Has been abandonded in favor of more focused projects (see FR1D)]
[Leaving this archived in case Iwant to come back to it later]

 Explorations in solving PDEs in one spatial dimention.

Structure
-
Grid
+ Class containg grid info: structured / unstructured, dx, num elemts, etc
+ Array containing the coorinates of points

Spatial Discretization
+ Define representation of solution on cell (class fxn)
+ Precompute geometric arrays (class fxn to generate arrays)

Equation
+ Define fluxes (class functions)
+ Designate character of PDE (clas attr)
+ Attempt to make as general as possible


Solver (if applicable)
+ Module with different methods

Temporal Discretization
+ Functions which integrate forwards in time
