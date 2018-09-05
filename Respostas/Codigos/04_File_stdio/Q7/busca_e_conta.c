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
 		//printf("O arquivo %s possui %ld bytes\n", nome_arquivo, tamanho);
 		return tamanho;

    } else {
        //printf("Arquivo inexistente\n");
        return 0;
    }

 	fclose(arquivo); 
}

void le_arq_texto(char *nome_arquivo, char *conteudo, char *procurado){

 int tamanho = tam_arq_texto(nome_arquivo);
 char cont[tamanho];
 char word[100];
 char *testa;
 int comp;
 int totalwords=0;
 FILE *arquivo;
 int i, j=0, repetido=0, k=0;

 arquivo = fopen(nome_arquivo, "r");
 
 if(!arquivo)
 {
   printf( "Erro na abertura do arquivo ou arquivo inexistente.\n");
   exit(0);
 }

  fread(&cont,sizeof(char),tamanho,arquivo);

  conteudo = cont;
  printf("%s",cont);

  for(i = 0; cont[i] != '\0'; i++)
	{
		
		if(cont[i] == ' ' || cont[i] == '\n' || cont[i] == '\t')
		{
			testa = word;
			printf("%s\n",testa);
			comp = strcmp(testa,procurado);
			if (comp==0)repetido++;
			totalwords++;
			j++;
			testa = NULL;
			k=0;

		} 
		word[k]=cont[i];
		k++;
	}

	printf("\n The Total Number of Words in this String %s  = %d\n", cont, totalwords);
	printf("%d\n", repetido);
fclose(arquivo);
}


int main(int argc,char * argv[]){

char *conteudo;
le_arq_texto(argv[2],conteudo,argv[1]);

return 0;
}