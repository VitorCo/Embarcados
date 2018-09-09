#include <string.h>
#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int tam_arq_texto(char *nome_arquivo){

char arquivo;
long tamanho;

arquivo = open(nome_arquivo, O_RDWR);

if(arquivo==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}
else{       
        tamanho = lseek(arquivo, 0, SEEK_END); // movimenta a posição corrente de leitura no arquivo para o seu fim
        
 		//printf("O arquivo %s possui %ld bytes\n", nome_arquivo, tamanho);
 		return tamanho;
 	}
 	close(arquivo); 
}

char* le_arq_texto(char *nome_arquivo){

int tamanho = tam_arq_texto(nome_arquivo);

 char arquivo;
 char *conteudo;

 conteudo = (char*)malloc(tamanho);
 arquivo = open(nome_arquivo, O_RDWR);
 
 if(arquivo==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

  read(arquivo,conteudo,sizeof(char)*tamanho);

  close(arquivo); 
  return conteudo;
}

