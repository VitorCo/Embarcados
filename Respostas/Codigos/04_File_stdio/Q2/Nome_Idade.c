#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){

FILE *fp;
fp = fopen ("Nome_Idade.txt", "w");
char nome[50];
char idade[10];
char frase_nome[70] = "Nome: ";
char frase_idade[20] = "Idade: ";

int i;

if(!fp)
	{
	printf( "Erro na abertura do arquivo");
    exit(0);
	}

printf("Digite o seu nome: ");
fgets(nome,50,stdin);
printf("Digite a sua idade: ");
fgets(idade,10,stdin);

strcat(frase_nome, nome);
strcat(frase_idade, idade);
strcat(frase_idade, " anos");

for(i=0; frase_nome[i]!='\0'; i++) 
putc(frase_nome[i], fp);

for(i=0; frase_idade[i]!='\0'; i++) 
putc(frase_idade[i], fp);

fclose(fp);
return 0;
}