// 显示回显位的状态
//

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int main(){
    struct termios info;
    int rv;

    rv = tcgetattr(0,&info);
    if(rv == -1){
        fprintf(stderr,"can not get stdin info\n");
        exit(0);
    }

    if(info.c_lflag & ECHO){
        printf("Echo is on\n");
    } else {
        printf("Echo is off\n");
    }

    return 0;
}
