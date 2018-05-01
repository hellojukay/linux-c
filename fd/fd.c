#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// 对于比较新的linux操作系统，有一个/dev/fd文件夹，里面默认有0,1,2这三个文件，分表表示，标准输入，标准输出，标准错误输出
int main(){
    int fd = open("/dev/fd/1",O_RDWR);
    char* buffer = "Hello World";
    int len = strlen(buffer);
    write(fd,buffer,len);
    return 0;
}