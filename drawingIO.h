
/*
  This file contains the IO functions for writing to Adobe PostScript.
  These functions will be called when stepping through fractal geometries.
  The intention is to allow for commandline arguments to be passed to 
  specify the file name and shape that one seeks to draw.

  It should be noted that NO maths should be done here and that this is
  strictly an interface for the IO.  
*/

void makeFile(char *FILE_PATH); // Makes a text file at specified path

void makeHeader(); // Prints header to the file

void strokeStep(double *point1[], double *point2[]); // Makes a brush stroke
