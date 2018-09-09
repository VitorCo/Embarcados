#include <stdio.h>	// Para a funcao printf()
#include <fcntl.h>	// Para a funcao open()
#include <unistd.h>	// Para a funcao close()
#include <stdlib.h>	// Para a função exit()

int main(int argc, const char * argv[]){

int fp;
char texto[100] = "Olá Mundo!\n";
fp = open("ola_mundo.txt",O_RDWR | O_CREAT);

if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

write(fp,texto,sizeof(texto));
close(fp);
return 0;
}

