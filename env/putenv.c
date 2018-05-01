#include <stdlib.h>
#include <stdio.h>

int main(){
    putenv("name=hellojukay");
    char* name=getenv("name");
    printf("name=%s",name);
    return 0;
}