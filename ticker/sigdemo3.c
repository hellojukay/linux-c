#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define INOUTLEN 100

int main(int argc, char **argv) {
    void inthandler(int);
    void quithandler(int);

    char input[INOUTLEN];

    int nchars;

    signal(SIGINT,inthandler);
    signal(SIGQUIT,quithandler);

    do {
        printf("\nType a message\n");
        nchars = read(0, input, (INOUTLEN -1));
        if(nchars == -1) {
            perror("read return an error\n");
        } else {
            input[nchars] = '\0';
            printf("You typed: %s",input);
        }
    } while(strncmp(input,"quit",4) != 0);
}

void inthandler(int s) {
    printf("Received signal %d ..waiting\n",s);
    sleep(2);
    printf("Leaving inthandler\n");
}

void quithandler(int s) {
    printf("Recived signal %d.. waiting\n",s);
    sleep(3);
    printf("Leaving quithandler\n");
}
