// 读取用户用户
//
//
#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

#define QUESTION "Do you want another transction"


int get_resonse(char *);

int main(){
    int reponse;
    reponse = get_resonse(QUESTION);
    return reponse;
}

int get_resonse(char *question) {
    printf("%s (y/n)?",question);
    while(1) {
        switch(getchar()) {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
        }
    }
}
