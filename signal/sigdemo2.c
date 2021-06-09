// 忽略信号
// 忽略信号以后 Ctrl C 无法退出，按 Ctrl + \  可以退出程序
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
