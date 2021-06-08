#include <stdio.h>
#include <fcntl.h>
#include <string.h>


#define BUFSIZE 1024

void usage(){
    printf("uage: write0 ttyname\n");
}
int main(int ac, char * av[]){
    int fd;
    char buf[BUFSIZE];

    if(ac != 2){
        usage();
        exit(1);
    }

    fd = open(av[1],O_WRONLY);
    if(fd == -1){
        printf(stderr,"open not open file %s",av[1]);
        exit(1);
    }

    while(fgets(buf,BUFSIZE,stdin) != NULL){
        if(write(fd,buf,strlen(buf)) == -1){
            break;
        }
    }
    close(fd);
}
