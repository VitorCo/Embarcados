#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){

FILE *fp;
fp = fopen ("ola_mundo.txt", "w");
char string[20] = "Ola Mundo!";
int i;

if(!fp)
	{
	printf( "Erro na abertura do arquivo");
    exit(0);
	}

for(i=0; string[i]!='\0'; i++) 
putc(string[i], fp);
putc('\n', fp);

fclose(fp);
return 0;
}