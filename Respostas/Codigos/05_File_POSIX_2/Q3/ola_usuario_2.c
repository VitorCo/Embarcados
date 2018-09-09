#include <string.h>
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char *argv[]){

char fp;
char nome_arquivo[50];
char frase_nome[70] = "Nome: ";
char frase_idade[20] = "Idade: ";
char extensao[10] = ".txt";

strcpy(nome_arquivo, argv[1]);
strcat(nome_arquivo, extensao);

fp = open(nome_arquivo, O_RDWR | O_CREAT);

if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

strcat(frase_nome, argv[1]);
strcat(frase_idade, argv[2]);
strcat(frase_idade, " anos");

write(fp,frase_nome,sizeof(char)*70);
write(fp,"\n",sizeof(char));
write(fp,frase_idade,sizeof(frase_idade));
write(fp,"\n",sizeof(char));

close(fp);
return 0;
}