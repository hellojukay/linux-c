// 处理信号

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main() {
    void f(int);

    signal(SIGINT, f);
    for(int i = 0; i < 100 ; i++) {
        sleep(1);
        printf("%d\n",i);
    }
}

void f(int signum) {
    printf("get singla %d\n",signal);
}
