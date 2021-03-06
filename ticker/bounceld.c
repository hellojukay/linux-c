#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include<string.h>
#include<sys/time.h>

#define MESAGE "Hello"
#define BLANK "      "

int row;
int col;
int dir;

int main() {
    int delay;
    int ndelay;
    int c;
    void move_msg(int);

    initscr();
    crmode();
    noecho();
    clear();

    row = 10;
    col =0;
    dir = 1;
    delay = 200;

    move(row,col);
    addstr(MESAGE);
    signal(SIGALRM, move_msg);
    set_ticker(delay);

    while(1) {
        ndelay = 0;
        c = getch();
        if(c == 'Q'){
            break;
        }

        if(c == ' ') {
            dir = -dir;
        }
        if(c == 'f' && delay > 2) {
            ndelay = delay / 2;
        }
        if(c == 's') {
            ndelay = delay * 2;
        }

        if(ndelay > 0) {
            set_ticker(delay = ndelay);
        }
    }
    endwin();
    return 0;
}

void move_msg(int signum) {
    signal(SIGALRM,move_msg);

    move(row,col);
    addstr(BLANK);
    col += dir;
    move(row,col);
    addstr(MESAGE);

    refresh();

    if(dir == -1 && col <=0 ) {
        dir = 1;
    } else {
        if(dir == 1 && col + strlen(MESAGE) >= COLS) {
            dir = -1;
        }
    }
}

int set_ticker(int n_msces) {
    struct itimerval new_timeset;
    long n_sec, n_usec;

    n_sec = n_msces / 1000;
    n_usec = (n_msces % 1000 ) * 1000L;
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usec;

    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usec;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
