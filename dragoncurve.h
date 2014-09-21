
#include "drawingIO.h"

double X(int mod, double t); // x parametrization
double Y(int mod, double t); // y parametrization
void computeTurnDirection(FILE * f,int order);
//double X(int mod, double t); // x parametrization
//double Y(int mod, double t); // y parametrization


double static calculateTimeStep(double x, double y, double t, double *timeStep);


//void advanceStep(double *x, double *y, double *t);
