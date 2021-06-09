// 忽略信号

#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main() {
    signal(SIGINT,SIG_IGN);

    while(1) {
        sleep(1);
        printf("haha\n");
    }
}
