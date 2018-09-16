#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int v_global=0;

void Incrementa_Variavel_Global(pid_t id_atual)
{
	
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main(int argc, const char *argv[]){

	int pid_filho[4];
	int i;
	int j=1;

pid_filho[0] = fork();

for(i=0;i<3;i++){

	if (pid_filho[i] == 0)
	{
	Incrementa_Variavel_Global(getpid());
	//printf("Eu sou processo filho: %d pid= %d mypid=%d\n",i, pid_filho[i], getpid());
	}
	else{
	pid_filho[j] = fork();
	j++;
	}

 }
return 0;
}