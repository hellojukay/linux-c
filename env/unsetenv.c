#include <stdlib.h>
#include <stdio.h>

int main(){
    unsetenv("name");
    char *name=getenv("name");
    printf("name = %s" , name);
    return 0;
}