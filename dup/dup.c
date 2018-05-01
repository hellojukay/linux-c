#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = dup(1);
    char* buffer = "Hello World\n";
    int len = strlen(buffer);
    int count = write(fd,buffer,len);
    printf("%d chars wirte %d to stdout",len,count);
    return 0;
}