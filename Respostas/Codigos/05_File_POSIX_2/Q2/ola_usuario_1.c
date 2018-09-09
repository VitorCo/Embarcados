#include <string.h>
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char *argv[]){

char fp;
char nome[50];
char nome_arquivo[50];
char idade[10];
char frase_nome[70] = "Nome: ";
char frase_idade[20] = "Idade: ";
char extensao[10] = ".txt";

printf("Digite o seu nome: ");
gets(nome);
printf("Digite a sua idade: ");
gets(idade);

strcpy(nome_arquivo, nome);
strcat(nome_arquivo, extensao);

fp = open(nome_arquivo, O_RDWR | O_CREAT);

if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

strcat(frase_nome, nome);
strcat(frase_idade, idade);
strcat(frase_idade, " anos");

write(fp,frase_nome,sizeof(frase_nome));
write(fp,"\n",sizeof(char));
write(fp,frase_idade,sizeof(frase_idade));
write(fp,"\n",sizeof(char));

close(fp);
return 0;
}