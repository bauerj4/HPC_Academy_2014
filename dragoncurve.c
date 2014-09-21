
/*
  This file shall contain the mathematics for the dragon curve and it shall
  execute print statments from drawingIO to create the postscript.  

*/

#include "drawingIO.h"
#include <math.h>

// Return 0 for right and 1 for left

double X(int modulus, double prevx)
{
  if (modulus % 4 == 2 || modulus % 4 == 0)
    {
      if (modulus % 4 == 2)
	{
	  return (prevx + 1.0);
	}
      else
	{
	  return (prevx - 1);
	}
    }

  else
    {
      return prevx;
    }
}

double Y(int modulus, double prevy)
{
  if (modulus % 4 == 1 || modulus % 4 == 3)
    {
      if (modulus % 4 == 1)
	{
	  return (prevy + 1.0);
	}
      else
	{
	  return (prevy - 1);
	}
      // return (prevy + 1);
    }
  
  else 
    {
      return prevy;
    }
    
}


void computeTurnDirection(char * FILENAME, int order)
{
  int i;
  int n = 1;
  for (i = 0; i<order; i++)
    {
      n *= 2;
    }
  int turns[n-1];
  
  int size = sizeof(turns)/sizeof(turns[0]);
  printf("size = %d\n", size);
  printf("n = %d\n", n);

  int k,l;
  for (i = 1; i<=n; i++)
    {
      k = i;
      l = 0;
      //printf("Benchmark 1.\n");
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
	  turns[i] = 0;
	}

      else if ((k % 4) == 1)
      {
	turns[i] = 0;
	printf("Right.\n");
	printf("%d\n",turns[i]);
      }
      
      else if ((k%4) == 3)
	{
	  turns[i] = 1;
	  printf("Left.\n");
	  printf("%d\n",turns[i]);
	}
      //printf("Loop.\n");
    }
  for (i=0;i<(n-1);i++)
    {
      printf("Element = %d\n",turns[i]);
    }
  // printf("Proper size in loop = %d\n", sizeof(turns));
  int modulus = 0;
  double x0 = 182.;
  double y0 = 98.;
  /*
if (turns[0] == 0 && i!=0)
  {
    strokeStep();
    modulus = modulus + 1;
  }
 
 else
   {
     modulus = modulus - 1;
   }
  */
  printf("Making file...\n");
  FILE * f = makeFile(FILENAME);
  printf("File made. Making header...\n");
  makeHeader(f);
  printf("Header made.\n");
  double prevx = x0;
  double prevy = y0; 
  double x,y;

  for (i=0; i < (n-1); i++)
    {
      printf("Loop %d\n",i);
      if (turns[i] == 0)
	{
	  x = X(modulus,prevx);
	  y = Y(modulus, prevy);
	  strokeStep(f, prevx, prevy);
	  prevx = x;
	  prevy = y;
	  modulus = modulus + 1;
	}
      
      else
	{
	  x = X(modulus,prevx);
	  y = Y(modulus, prevy);
	  strokeStep(f, x, y);
	  prevx = x;
	  prevy = y;
	  modulus = modulus - 1;
	}
    }
  finishFile(f);
}

/*
  Coordinates may be gotten by storing the orientation.  Consider a North-South-  East-West global orientation.  The algorithm we seek to develop maps a turn
  onto a global movement. 

  n Modulo 4 with a left step being -1 and right being +1
  should take n in absolute value.  
*/


/*
double X(int modulus, double prevx)
{
  if (modulus % 4 == 2 || modulus % 4 == 0)
    {
      return (prevx + 1.0);
    }

  else
    {
      return prevx;
    }
}

double Y(int modulus, double prevy)
{
  if (modulus % 4 == 1 || modulus % 4 == 3)
    {
      return (prevy + 1);
    }
  
  else 
    {
      return prevy;
    }
    
}



double static calculateTimeStep(double x, double y, double t, double *timeStep)
{
  return 0.0;
}


void advanceStep(double *x, double *y, int modulus)
{
  
}
*/
