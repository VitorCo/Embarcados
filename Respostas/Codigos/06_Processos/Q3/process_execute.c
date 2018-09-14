#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int i=1;
	char *lista_de_argumentos[2] = {NULL, NULL};

	while(i<argc){
		lista_de_argumentos[0] = argv[i];

		if(fork()==0){
			execvp(lista_de_argumentos[0],lista_de_argumentos);
			printf("\n");
			return 0;
		}
		i++;
	}
	wait(NULL);
	return 0;
}


