// 关闭终端缓冲模式
#include<stdio.h>
#include<termios.h>

#define QUESTION "Do you want another transactions"

int get_response(char *question);
int tty_mode(int how);
void set_crmode();

int main(){
    int reponse;
    tty_mode(0);
    set_crmode();

    reponse = get_response(QUESTION);

    tty_mode(1);
    
    return reponse;
}

int get_response(char *question) {
    int input;
    printf("%s (y/n)?",question);

    while(1) {
        switch(input = getchar()) {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N':
            case EOF: return 1;
            default:
                printf("\n can not understand %c,", input);
                printf("Please type y or n \n");
        }
    }
}

void set_crmode(){
    struct termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}


int tty_mode(int how) {
    static struct termios origin_mode;
    if(!how) {
        tcgetattr(0, &origin_mode);
    } else {
        return tcsetattr(0, TCSANOW, &origin_mode);
    }
}
