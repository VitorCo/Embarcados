#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	
	int pid;
	int fd[2];
	int i;

	pipe(fd);
	pid = fork();

	for(i=0;i<10;i++){

		if(pid!=0){
			int numeros_escritos[10] = {1,2,3,4,5,6,7,8,9,10};
			if(write(fd[1], numeros_escritos+i, sizeof(int))<0)
			printf("Erro na escrita do pipe.\n");
			sleep(1);
		}
		else{

			int numeros_lidos[1];
			if(read(fd[0], numeros_lidos, sizeof(int))<0)
				printf("Erro na escrita do pipe.\n");
			else
				printf("Valor lido pelo filho: %d\n",numeros_lidos[0]);			
		}


	}

	return 0;
}