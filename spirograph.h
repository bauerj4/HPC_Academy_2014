
/*
  This file shall contain the mathematics for the spirograph and it shall
  execute print statments from drawingIO to create the postscript.  

*/

#include "drawingIO.h"

double static X(double t); // x parametrization
double static Y(double t); // y parametrization


/*
  Computes a new stepsize based on the current values of the state variables.
  This is necessary because of the order of magnitude varying length scales
  in fractal geometries, and with the spirograph in particular.
*/

 void  static calculateTimeStep(double x, double y, double t, double *timeStep);

/*
  Performs calculation of spirogaph at a timestep.  Calls timestep recalculation
  and updates variables passed by reference.  Postscript lines are printed
  as well.
*/

void advanceStep(double *x, double *y, double *t);
