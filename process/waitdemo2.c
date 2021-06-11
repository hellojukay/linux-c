#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


#define DELAY 10

int main() {
    int newpid ;

    void child_code(int);
    void parent_code(int);

    if((newpid = fork()) == -1){
        perror("fork");
    } else if(newpid == 0) {
        child_code(DELAY);
    } else {
        parent_code(newpid);
    }
    return 0;
}

void child_code(int delay) {
    printf("child %d here , will sleep %d seconds\n",getpid(),delay);
    sleep(delay);

    printf("child done, exit");
    exit(17);
}

void parent_code(int child_pid) {
    int wait_rv;
    int child_status;

    int high_8, low_7,bit_7;

    wait_rv = wait(&child_status);

    printf("donw waiting for %d, wait return %d\n",child_pid,wait_rv);

    high_8 = child_pid >> 8;
    low_7 = child_pid & 0X7F;
    bit_7 = child_pid & 0X80;
    printf("status exit =%d,sig=%d,core=%d\n",high_8,low_7,bit_7);
}
