// 忽略非法字符

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>

#define QUESTION "Do you want another tansacions"

int get_reponse(char*);
int tty_mode();
void set_cr_noecho_mode();


int main(){
    int reponse;

    tty_mode(0);
    set_cr_noecho_mode();

    reponse = get_reponse(QUESTION);

    tty_mode(1);
    return reponse;
}

int get_reponse(char *request) {
    int input;
    printf("%s (y/n)?",request);
    while(1) {
        switch (input = getchar()) {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
        }
    }
}
void set_cr_noecho_mode() {
    struct termios info;
    tcgetattr(0, &info);

    info.c_lflag &= ~ICANON;
    info.c_lflag &= ~ECHO;
    info.c_cc[VMIN] = 1;

    tcsetattr(0,TCSANOW,&info);
}

int tty_mode(int how) {
    static struct termios origin_mode;
    if(!how) {
        tcgetattr(0,&origin_mode);
    } else {
        tcsetattr(0, TCSANOW, &origin_mode);
    }
}
