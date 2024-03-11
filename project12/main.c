// Date:2024/3/11
// Author:妖怪鱼
// Introduction: I/O多路转接模型和select(chat2)
#include "func.h"

int main()
{
    int fdw = open("../project11/01.pipe", O_WRONLY);
    int fdr = open("../project11/02.pipe", O_RDONLY);
    printf("我是聊天二号机\n");
    char buf[128] = { 0 };
    fd_set rdset; // 创建监听集合
    while (1) {
        FD_ZERO(&rdset); // 清空集合
        FD_SET(STDIN_FILENO, &rdset); // 将标准输入加入集合
        FD_SET(fdr, &rdset); // 将要读取的管道文件加入集合
        select(fdr + 1, &rdset, NULL, NULL, NULL); // 调用select函数阻塞当前进程
        if (FD_ISSET(fdr, &rdset)) {
            memset(buf, 0, sizeof(buf));
            int ret = read(fdr, buf, sizeof(buf));
            if (ret == 0) {
                printf("结束!!!!\n");
                break;
            }
            printf("读取到管道中的内容:%s\n", buf);
        }
        if (FD_ISSET(STDIN_FILENO, &rdset)) {
            memset(buf, 0, sizeof(buf));
            int ret = read(STDIN_FILENO, buf, sizeof(buf)); // 从标准输入中读取内容
            if (ret == 0) {
                printf("关闭成功!!!!\n");
                break;
            }
            write(fdw, buf, sizeof(buf));
        }
    }
    return 0;

}




