#include <unistd.h>

int main(){
    // 创建一个软链
   symlink("/home/hellojukay","/home/hellojukay/link");
   return 0;
}