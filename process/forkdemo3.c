#include<stdio.h>
#include<unistd.h>

int main() {
    int fork_v;
    printf("Before: my pid is %d\n",getpid());

    fork_v = fork();

    if(fork_v == -1) {
        perror("fork");
    } else if(fork_v == 0) {
        printf("I am the child my pid = %d\n",getpid());
    } else {
        printf("I am the parent . my child is %d\n",fork_v);
    }
    return 1;
}