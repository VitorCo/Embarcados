#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long int maior[4];

void* procura_1(void *v){

  long int *num = (long int *) v;
  maior[0] = num[0];
  for (int k = 1; k < 12500; k++)
  {
    if (num[k] > maior[0])
    {
       maior[0]  = num[k];
    }
  }
  printf("%ld\n", maior[0]);
return NULL;
}
void* procura_2(void *v){

  long int *num = (long int *) v;
  maior[1] = num[12500];
  for (int k = 12501; k < 25000; k++)
  {
    if (num[k] > maior[1])
    {
       maior[1]  = num[k];
    }
  }
    printf("%ld\n", maior[1]);
return NULL;
}
void* procura_3(void *v){

  long int *num = (long int *) v;
  maior[2] = num[25000];
  for (int k = 25001; k < 37500; k++)
  {
    if (num[k] > maior[2])
    {
       maior[2]  = num[k];
    }
  }
    printf("%ld\n", maior[2]);
return NULL;
}
void* procura_4(void *v){

  long int *num = (long int *) v;
  maior[3] = num[37500];
  for (int k = 37501; k < 50000; k++)
  {
    if (num[k] > maior[3])
    {
       maior[3]  = num[k];
    }
  }
    printf("%ld\n", maior[3]);
return NULL;
}

int main()
{
  pthread_t thread_id1;
  pthread_t thread_id2;
  pthread_t thread_id3;
  pthread_t thread_id4;

  long int maximum;
  long int v[50000];
  int c;
 
  for (c = 0; c < 50000; c++){
    v[c] = rand();
  }
 
  pthread_create (&thread_id1, NULL, &procura_1, &v);
  pthread_create (&thread_id2, NULL, &procura_2, &v);
  pthread_create (&thread_id3, NULL, &procura_3, &v);
  pthread_create (&thread_id4, NULL, &procura_4, &v);

  pthread_join (thread_id1, NULL);
  pthread_join (thread_id2, NULL);
  pthread_join (thread_id3, NULL);
  pthread_join (thread_id4, NULL);

  maximum = maior[0];
 
  for (c = 1; c < 3; c++)
  {
    if (maior[c] > maximum)
    {
       maximum  = maior[c];
    }
  
  }
printf("%ld\n", maximum);
return 0;
}