#include <string.h>
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()
#include "bib_arqs.h"

int main(int argc,char * argv[]){

int i,j=0;
char *conteudo;
char palavra[50];
int repetido=0;
conteudo = le_arq_texto(argv[2]);

for(i = 0; conteudo[i] != '\0'; i++)
	{
		palavra[j] = conteudo[i];		

		if(conteudo[i] == ' ' || conteudo[i] == '\n' || conteudo[i] == '\t')
		{
			palavra[j]='\0';
			if (strcmp(palavra,argv[1])==0)repetido++;
			j=-1;
		}
		j++;
	}

free(conteudo);
printf("%s ocorre %d vezes no arquivo %s.\n",argv[1], repetido, argv[2]);
return 0;
}