#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){

FILE *fp;
fp = fopen ("Nome_Idade.txt", "w");

char frase_nome[100] = "Nome: ";
char frase_idade[20] = "Idade: ";

int i;
int j=1;

if(!fp)
	{
	printf( "Erro na abertura do arquivo");
    exit(0);
	}

while(j<argc-1)
	{
	strcat(frase_nome, argv[j]);
	strcat(frase_nome, " ");
	j++;
	}

strcat(frase_idade, argv[j]);
strcat(frase_idade, " anos");

for(i=0; frase_nome[i]!='\0'; i++) 
putc(frase_nome[i], fp);
putc('\n', fp);

for(i=0; frase_idade[i]!='\0'; i++) 
putc(frase_idade[i], fp);

putc('\n', fp);

fclose(fp);

return 0;
}