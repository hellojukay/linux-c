#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void main() {
    void wakeup();
    printf("abort to sleep for 4 seconds\n");

    signal(SIGALRM,wakeup);

    alarm(4);

    pause();
    printf("Morning is soon?\n");
}

void wakeup() {
    printf("Alarm received from kernel\n");
}
