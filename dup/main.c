#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fh = open("a.txt",O_CREAT|O_APPEND|O_WRONLY,0644);
    // 将写入到 a.txt 文件的数据写入到 1 , 也就是 a.txt 
    dup2(1,fh);
    char* msg = "hello World";
    write(fh,msg,strlen(msg));
    fflush(stdout);
    close(fh);
}

