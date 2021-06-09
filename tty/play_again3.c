// 非阻塞IO
//
#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<string.h>

#define ASK "Do you want another transaction"
#define TRIES 3
#define SLEEPTIME 2
#define BEEP putchar('\a')

void tty_mode(int);
int get_reponse(char *,int);
int get_ok_char();
void set_cr_noecho_mode() 
void set_nodelay_mode();

int main() {
    int response;
    tty_mode(0);
    set_cr_noecho_mode();
    set_nodelay_mode();
    response = get_reponse(ASK,TRIES);
    tty_mode(1);
    return response;
}

int get_reponse(char *question, int maxtrics) {
    int input;
    printf("%s (y/n)?",question);
    fflush(stdout);

    while(1) {
        sleep(SLEEPTIME);
        input = tolower(get_ok_char());
        if(input == 'y') {
            return 0;
        }
        if(input == 'n') {
            return 1;
        }
        if(maxtrics-- == 0) {
            return 2;
        }
    }
}

int get_ok_char() {
    int c ;
    while((c = getchar()) != EOF && strchr("yYnN",c) == NULL){
        ;
    }
    return c;
}

void set_cr_noecho_mode() {
    struct termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&ttystate)
}

void set_nodelay_mode() {
    int termflags;
    termflags = fcntl(0,F_GETFL);
    termflags |= O_NDELAY;
    fcntl(0,F_SETFL,termflags);
}

void tty_mode(int how) {
    static struct termios origin_mode;
    static int origin_flags;

    if(!how) {
        tcgetattr(0, &origin_mode);
        origin_flags = fcntl(0,F_GETFL);
    } else {
        tcsetattr(0, TCSANOW,&origin_mode);
        fcntl(0, F_SETFL,origin_mode);
    }
}
