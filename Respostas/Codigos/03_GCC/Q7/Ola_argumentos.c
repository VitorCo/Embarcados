#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
int i=1;
printf("Argumentos: ");
while(i<argc){
printf("%s ", argv[i]);
i++;
}
return 0;
}
