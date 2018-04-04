#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    if(argc < 3){
        printf("args errors");
        return 1;
    }
    char *input = argv[1];
    char *output = argv[2];
    int inputFD = open(input,O_RDONLY);
    int outFD = open(output,O_RDWR);
    int SIZE = 1024 * 4;
    char buffer[SIZE];
    int n = 0;
    while(1){
        n = read(inputFD,buffer,SIZE);
        if(n > 0){
            write(outFD,buffer,n);
        }else{
            close(inputFD);
            close(outFD);
        }
    }
    return 0;
}