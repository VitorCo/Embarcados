#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){

	pid_t pid_filhos;
	int i;

for(i=1;i<4;i++){

	pid_filhos= fork();
	printf("Eu sou processo: %d pid= %d mypid=%d\n",i, (int) pid_filhos, getpid());

	if (pid_filhos == 0)
	{
		break;
	}

 }

return 0;
}