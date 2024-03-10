#include "func.h"

int main(){
    char* pipeName = "1.pipe";
    int fdr = open(pipeName, O_RDONLY); // 以读的形式打开管道
    ERROR_CHECK(fdr, -1, "open");
    char buf[128] = { 0 };
    read(fdr, buf, sizeof(buf)); // 从管道中读取数据
    printf("读到的数据:%s\n", buf);
    close(fdr);
    return 0;
}
