// Date:2024/3/10
// Author:妖怪鱼
// Introduction:两个管道实现全双工通信复习:chat2
#include "func.h"

int main()
{
    int fdw = open("../project09/01.pipe", O_WRONLY | O_CREAT | O_TRUNC);
    int fdr = open("../project09/02.pipe", O_RDONLY);
    printf("我是聊天二号机");
    char buf[128] = { 0 };
    while (1) {
        memset(buf, 0, sizeof(buf));
        read(fdr, buf, sizeof(buf));
        printf("读取到管道中的内容:%s\n", buf);
        memset(buf, 0, sizeof(buf));
        read(STDIN_FILENO, buf, sizeof(buf));
        write(fdw, buf, sizeof(buf));
    }
    return 0;
}
