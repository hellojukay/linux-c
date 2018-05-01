#include <stdlib.h>
#include <stdio.h>
int main(){
    char* name=getenv("name");
    printf("name = %s\n",name);
    return 0;
}
// name=hellojukay ./a.out