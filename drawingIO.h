
#include <stdio.h>

/*
  This file contains the IO functions for writing to Adobe PostScript.
  These functions will be called when stepping through fractal geometries.
  The intention is to allow for commandline arguments to be passed to 
  specify the file name and shape that one seeks to draw.

  It should be noted that NO maths should be done here and that this is
  strictly an interface for the IO.  
*/

FILE * makeFile(const char *); // Makes a text file at specified path

void makeHeader(FILE * , double , double ); // Prints header to the file

void strokeStep(FILE * , double , double ); // Makes a brush stroke

void finishFile(FILE * );

void strokeStepMulti(FILE * , double , double , int );

void strokeStepGrad(FILE * , double , double , int , int );

