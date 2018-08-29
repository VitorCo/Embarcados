#include <stdio.h>
#include <stdlib.h>
#include "Num_Caracs.h"

int main(int argc, char **argv)
{
int i=0;
while(i<argc){
char *string = argv[i];
printf("Argumento: %s / Numero de caracteres: %d\n", argv[i],Num_Caracs(string));
i++;
}
return 0;
}
