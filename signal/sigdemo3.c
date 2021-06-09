#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>


void handle_sig2(int signum) {
    exit(0);
}
void handle_sig1(int signum) {
    signal(SIGINT,handle_sig2);
}
int main() {
   signal(SIGINT,handle_sig1);

   while(1) {
       printf("sleep");
       sleep(5);
   }
   return 0;
}
