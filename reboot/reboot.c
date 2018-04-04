#include <sys/reboot.h>
#include <stdio.h>

// 这里启动是必须要sudo的，不然不会重启，也不会报错
int main(void){
    printf("reboot now ...\n");
    reboot(RB_AUTOBOOT);
    return 0;
}