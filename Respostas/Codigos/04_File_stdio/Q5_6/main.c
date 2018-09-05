#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_arqs.h"

int main(int argc,char * argv[]){

char *conteudo;
conteudo = le_arq_texto(argv[1]);
printf("%s\n",conteudo);
free(conteudo);
return 0;
}