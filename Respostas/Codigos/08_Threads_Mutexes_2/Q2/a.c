#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
  int maximum,c;
  long int v[50000];
 
  for (c = 0; c < 50000; c++){
    v[c] = rand();
  }
 
  maximum = v[0];
 
  for (c = 1; c < 50000; c++)
  {
    if (v[c] > maximum)
    {
       maximum  = v[c];
    }
  }
 
  printf("Maximum element is %d.\n", maximum);
  return 0;
}