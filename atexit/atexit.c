#include <stdlib.h>
#include <stdio.h>
void fuck(){
    printf("%s\n","fuck");
}
void bitch(){
    printf("%s\n","bitch");
}
int main(){
    atexit(fuck);
    atexit(bitch);
    return 0;
}