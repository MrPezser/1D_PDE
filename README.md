# 1D_PDE
 Explorations in solding PDEs in one spatial dimention

Structure
-
Grid
+ Class containg grid info: structured / unstructured, dx, num elemts, etc
+ Array containing the coorinates of points

Equation
+ Define fluxes (class functions)
+ Designate character of PDE (clas attr)
+ Attempt to make as general as possible

Spatial Discretization
+ Define representation of solution on cell (class fxn)
+ Precompute geometric arrays (class fxn to generate arrays)

Solver (if applicable)
+ Module with different methods

Temporal Discretization
+ Functions which integrate forwards in time