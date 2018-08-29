#include <stdio.h>
#include <stdlib.h>
#include "Num_Caracs.h"

int main(int argc, char **argv)
{
int i=0;
int cont = 0;
while(i<argc){
char *string = argv[i];
cont = cont+Num_Caracs(string);
i++;
}

printf("Total de caracteres de entrada: %d\n", cont);

return 0;
}
