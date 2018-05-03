#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t p = getpid();
    printf("father pid = %d\n",p);
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // 后面如果不sleep,父进程可能先退出，然后子进程被 1 号进程托管，这里返回的就是pid就是1
       pid_t father_pid =  getppid();
       printf("father pid = %d\n",father_pid);
    }else{
        printf("child pid = %d\n",child_pid);
    }
    sleep(1000);
    return 0;
}