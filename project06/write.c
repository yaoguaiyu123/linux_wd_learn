#include "func.h"

int main(){
    char* pipeName = "1.pipe";
    int fdw = open(pipeName, O_WRONLY); // 以读的形式打开管道
    ERROR_CHECK(fdw, -1, "open");
    write(fdw, "nihaoshijie", 11); // 向管道中写入数据
    close(fdw);
    return 0;
}
