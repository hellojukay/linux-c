#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int fh = open("a.txt",O_CREAT|O_APPEND|O_WRONLY,0644);
    if(fh < 0) {
        printf("can not create file a.txt\n");
        exit(0);
    }
    int offset = 0;
    char* msg = "hello world\n";
    for(int i =0 ; i< 10;i++){
        int len = pwrite(fh,msg,strlen(msg),offset);
        offset = offset + len;
    }
    close(fh);
}
