// Date:2024/3/10
// Author:妖怪鱼
// Introduction:两个管道实现全双工通信复习:chat1
#include "func.h"

int main()
{
    int fdr = open("../project09/01.pipe", O_RDONLY);
    int fdw = open("../project09/02.pipe", O_WRONLY | O_CREAT | O_TRUNC);
    printf("我是聊天一号机");
    char buf[128] = { 0 };
    while (1) {
        memset(buf, 0, sizeof(buf));
        read(STDIN_FILENO, buf, sizeof(buf)); // 从标准输入中读取内容
        write(fdw, buf, sizeof(buf));
        memset(buf, 0, sizeof(buf));
        read(fdr, buf, sizeof(buf));
        printf("读取到管道中的内容:%s\n", buf);
    }
    return 0;
}
