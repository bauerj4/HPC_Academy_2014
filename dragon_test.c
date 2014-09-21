#include "dragoncurve.h"
#include <stdio.h>

void main(void)
{
  //int i;
  //int * steps;
  char * filename = "test.ps";
  //printf("Proper size = %d",sizeof(*computeTurnDirection(3)));
  computeTurnDirection(filename,17);
  /*int size = sizeof(steps) / sizeof(steps[0]);
  printf("%d\n", sizeof(steps));
  printf("%d\n", steps[0]);
  printf("%d\n", *steps);
  for (i = 0; i < size; i++)
    {
      // printf("%d\n", i);
      printf("step of i = %d\n",steps[i]);
    }
  */
}
