#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void* recebe_numero(void *numero){

	int *num = (int *) numero;
	printf("%d\n", *num);
}

int main()
{

	pthread_t thread_id1;
	int i;

	for(i=0;i<=10;i++){
	pthread_create (&thread_id1, NULL, &recebe_numero, &i);
	sleep(1);
	}


	return 0;
}