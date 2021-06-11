#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define DELAY 4
void child_code(int);
void parent_code(int);

int main() {
    int newpid;

    printf("Before:my pid is %d\n",getpid());
    newpid = fork() ;
    if(newpid == 0) {
        child_code(DELAY);
    } else {
        parent_code(newpid);
    }
}

void child_code(int delay) {
    printf("child %d here will sleep %d seconds\n",getpid(),delay);
    sleep(delay);
    printf("child done ,about to exit\n");
    exit(17);
}

void parent_code(int childpid) {
    int wait_rv;
    wait_rv = wait(NULL);
    printf("done waiting for %d, waint returnd %d\n",childpid,wait_rv);
}