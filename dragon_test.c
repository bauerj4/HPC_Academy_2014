#include "dragoncurve.h"

void main(void)
{
  int i;
  int *steps = computeTurnDirection(3);
  int size = sizeof(steps) / sizeof(steps[0]);
  printf("%d\n", size);
  for (i = 0; i < size; i++)
    {
      //printf("%d\n", size);
      printf("%d\n",steps[i]);
    }
}
