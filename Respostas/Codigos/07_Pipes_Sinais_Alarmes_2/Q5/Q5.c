#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("ps axu | sort -nk 3 | tail");
	alarm(5);
}

void funcao_para_control_c()
{
	printf("\nProcesso terminado!\n");
	exit(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	signal(SIGINT, funcao_para_control_c);
	alarm(1);

	while(1);

	return 0;
}
