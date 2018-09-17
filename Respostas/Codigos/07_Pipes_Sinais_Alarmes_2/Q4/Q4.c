#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;
	int fd[2];
	// Cria o pipe
	pipe(fd);
	// Cria o processo
	pid = fork();
	// Codigo do filho
	if(pid == 0){

		char nome[50];
		printf("O processo filho gostaria de saber o nome do usuário:\n");
		gets(nome);

		if (write(fd[1], nome, sizeof(nome)) < 0){
			printf("Erro na escrita do pipe\n");
		}
	}
	else{

		char buffer[50];
		if(read(fd[0], buffer, 50) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("Obrigado processo filho, agora sabemos que o nome do usuário é %s.\n", buffer);
		sleep(2);
	}

return 0;
}