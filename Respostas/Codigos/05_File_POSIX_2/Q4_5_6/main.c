#include <string.h>
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include "bib_arqs.h"

int main(int argc,char * argv[]){

char *conteudo;
conteudo = le_arq_texto(argv[1]);
printf("%s",conteudo);
free(conteudo);
return 0;
}