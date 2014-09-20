/* Spirograph function that takes gives out the (x, y) coordinates to be drawn
   R = scaling parameter, giving an overall scale to the picture
   k = ratio of (radius of inner circle)/(radius of outer circle)
   l = distance of the pen from the center of the inner circle, 
       in units of r_inner
   delta_t = time step */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<libps/pslib.h>

int main(int argc, char *argv[]){
  if (argc != 5){
    printf("Wrong number of input arguments");
    return 0;
  }

  PSDoc *psdoc;
  PS_boot();
  psdoc = PS_new();
  PS_open_file(psdoc, "test.ps");
  PS_close(psdoc);
  PS_delete(psdoc);
  PS_shutdown();

  double R = atof(argv[0]);
  double k = atof(argv[1]);
  double l = atof(argv[2]);
  double delta_t = atof(argv[3]);
  if (k > 1.0 || l > 1.0){
    printf("Invalid value for input argument(s)");
    return 0;
  }
  double r_outer = k * R;
  double r_inner = 1 - k * R;
  double x0 = R * ((1 - k) * cos(0.0) + l);
  double y0 = R * ((1 - k) * sin(0.0) + l);
  double x = 0;
  double y = 0;
  int n = 0;
  while( (x != x0) && (y != y0)){
      x = R * ((1 - k) * cos(n * delta_t) + l);
      y = R * ((1 - k) * sin(n * delta_t) + l);
      printf("(%f, %f)\n", x, y);
      n++;
      //give coordinates to the postscript function?
  }
  return 0;
}
