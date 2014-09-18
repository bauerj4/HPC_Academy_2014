
/*
  This file shall contain the mathematics for the dragon curve and it shall
  execute print statments from drawingIO to create the postscript.  

*/

/*
  This is so broken right now :'(
*/

#include "drawingIO.h"
#include <math.h>

// Return 0 for right and 1 for left

int* computeTurnDirection(int order)
{
  int i;
  int n = 1;
  for (i = 0; i<order; i++)
    {
      n *= 2;
    }
  int turns[n-1];
  
  int size = sizeof(turns)/sizeof(turns[0]);
  // printf("%d\n", size);
  // printf("%d\n", n);

  int k,l;
  for (i = 0; i<n; i++)
    {
      k = i;
      l = 0;
      printf("Benchmark 1.\n");
      while (k % 2 == 0 && k != 0)
	{
	  k = k/2;
	  l = l + 1;
	}
      
      //      if (i == 0)
      //	{
      //	  print("Vertex created.\n");
      //	}
     
      if (i==0)
	{
	  printf("Vertex created.\n");
	}

      if ((k % 4) == 1);
      {
	turns[i] = 0;
	printf("%d\n", turns[i]);
      }
      
      if ((k%4) == 3)
	{
	  turns[i] = 1;
	  printf("%d\n", turns[i]);
	}
    }
  return turns;
}
double static X(double t)
{
  return 0.0;
}

double static Y(double t)
{
  return 0.0;
}



double static calculateTimeStep(double x, double y, double t, double *timeStep)
{
  return 0.0;
}


void advanceStep(double *x, double *y, double *t)
{
  printf("Null.");
}
