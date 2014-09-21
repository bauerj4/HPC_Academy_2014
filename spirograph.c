/* Spirograph function that takes gives out the (x, y) coordinates to be drawn
   R = scaling parameter, giving an overall scale to the picture
   k = ratio of (radius of inner circle)/(radius of outer circle)
   l = distance of the pen from the center of the inner circle, 
       in units of r_inner
   delta_t = time step */

#include<stdio.h>
#include<stdlib.h>
#include "drawingIO.h"
#include<math.h>
//#include<libps/pslib.h>

int main(int argc, char *argv[]){
  if (argc != 5){
    printf("Wrong number of input arguments");
    return 0;
  }

  /*PSDoc *psdoc;
  PS_boot();
  psdoc = PS_new();
  PS_open_file(psdoc, "test.ps");
  PS_close(psdoc);
  PS_delete(psdoc);
  PS_shutdown();*/

  const char * FILE_PATH;
  FILE *pFile;
  FILE_PATH = "filename.ps";

  double R = atof(argv[1]);
  double k = atof(argv[2]);
  double l = atof(argv[3]);
  double delta_t = atof(argv[4]);
  if (k > 1.0 || l > 1.0){
    printf("Invalid value for input argument(s)");
    return 0;
  }
  //double r_outer = k * R;
  //double r_inner = 1. - k * R;
  double x0 = R + R * ((1 - k) + l * k);
  double y0 =  R - R * (l * k);
  printf("%f, %f\n", x0, y0);
  double x = 0;
  double y = 0;
  int n = 0;
  double time;
  double lk = l * k;
  double rel = (1 - k) / k;
  pFile = makeFile(FILE_PATH);
  makeHeader(pFile);
  while ( n < 5000 ) {
    n++;
    time = delta_t * n; 
    x = R * ((1 - k) * cos(time) + lk * cos(rel * time)) + R;
    y = R * ((1 - k) * sin(time) - lk * sin(rel * time)) + R;
    //printf("(%f, %f)\n", x, y);
    strokeStep(pFile, x, y);
      //give coordinates to the postscript function?
  }
  finishFile(pFile);
  return 0;
}
