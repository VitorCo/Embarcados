#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){

	int i=1;

while(i<argc){

	system(argv[i]);
	printf("\n");
	i++;
}

return 0;
}