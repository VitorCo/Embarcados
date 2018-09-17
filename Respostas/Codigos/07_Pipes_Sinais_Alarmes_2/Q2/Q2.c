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
	if(pid == 0)
	{
		char buffer_filho[100], msg_filho[100];
		strcpy(msg_filho, "Pai, qual é a verdadeira essência da sabedoria?");
		
		if (write(fd[1], msg_filho, sizeof(msg_filho)) < 0){
			printf("Erro na escrita do pipe\n");
		}

		sleep(3);

		if(read(fd[0], buffer_filho, 100) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: %s\n", buffer_filho);

		sleep(3);

		strcpy(msg_filho, "Mas até uma criança de três anos sabe disso!");
		
		if (write(fd[1], msg_filho, sizeof(msg_filho)) < 0){
			printf("Erro na escrita do pipe\n");
		}

		sleep(3);

		if(read(fd[0], buffer_filho, 100) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: %s\n", buffer_filho);

	}
	// Codigo do pai
	else
	{
		char buffer_pai[100], msg_pai[100];
		strcpy(msg_pai, "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
		
		if(read(fd[0], buffer_pai, 100) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("FILHO: %s\n", buffer_pai);

		sleep(3);

		if (write(fd[1], msg_pai, sizeof(msg_pai)) < 0){
			printf("Erro na escrita do pipe\n");
		}
		
		sleep(3);

		strcpy(msg_pai, "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
		
		if(read(fd[0], buffer_pai, 100) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("FILHO: %s\n", buffer_pai);

		sleep(3);

		if (write(fd[1], msg_pai, sizeof(msg_pai)) < 0){
			printf("Erro na escrita do pipe\n");
		}

		sleep(3 );
	}
return 0;
}
