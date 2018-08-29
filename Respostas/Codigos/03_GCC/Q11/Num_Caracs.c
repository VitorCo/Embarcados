#include "Num_Caracs.h"

int Num_Caracs(char *string){
int i=0;

while(*string!='\0'){
i++;
string++;
}

return i;
}
