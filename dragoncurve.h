
#include "drawingIO.h"

void computeTurnDirection(FILE * f,int order);
double static X(int mod, double t); // x parametrization
double static Y(int mod, double t); // y parametrization


double static calculateTimeStep(double x, double y, double t, double *timeStep);


//void advanceStep(double *x, double *y, double *t);
