// 改变回显状态
//
#include<stdio.h>
#include<termios.h>
#include<stdlib.h>


int main(int ac, char *av[]){
    struct termios info;
    if(ac == 1){
        exit(1);
    }
    if(tcgetattr(0,&info) == -1){
        fprintf(stderr,"tcgetattr error\n");
        exit(1);
    } 
    
    if(av[1][0] == 'y') {
        info.c_lflag |= ECHO;
    } else {
        info.c_lflag = ~ECHO;
    }

    if(tcsetattr(0,TCSANOW,&info) == -1){
        fprintf(stderr,"set tc attr error\n");
        exit(1);
    }

    return 0;
}
