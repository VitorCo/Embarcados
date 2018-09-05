#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam_arq_texto(char *nome_arquivo){

FILE *arquivo;
long tamanho;

arquivo = fopen(nome_arquivo, "r");

if (arquivo != NULL) {
        
        fseek(arquivo, 0, SEEK_END); // movimenta a posição corrente de leitura no arquivo para o seu fim
        
        tamanho = ftell(arquivo); // pega a posição corrente de leitura no arquivo
 		printf("O arquivo %s possui %ld bytes\n", nome_arquivo, tamanho);
 		return tamanho;

    } else {
        printf("Arquivo inexistente\n");
        return 0;
    }

 	fclose(arquivo); 
}
