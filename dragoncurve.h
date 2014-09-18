
#include "drawingIO.h"

int* computeTurnDirection(int order);
double static X(double t); // x parametrization
double static Y(double t); // y parametrization


double static calculateTimeStep(double x, double y, double t, double *timeStep);


void advanceStep(double *x, double *y, double *t);
