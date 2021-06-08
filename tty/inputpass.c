// 输出密码信息

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

int main(){
    char buffer[1024];
    struct termios info;
    if(tcgetattr(0,&info) == -1){
        fprintf(stderr,"can open get terminal info\n");
        exit(1);
    }
    info.c_lflag = ~ECHO;
    printf("enter passwd:");
    scanf("%s",buffer);
    info.c_lflag = ECHO;
    printf("passwd: %s\n",buffer);
    
    return 0;
}
