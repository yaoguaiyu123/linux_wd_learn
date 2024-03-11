// Date:2024/3/11
// Author:妖怪鱼
// Introduction: I/O多路转接模型和select(chat1)

//I/O多路转接模型：在这种模型下，如果请求的I/O操作阻塞，且它不是真正阻塞I/O，而是让其中的
//一个函数等待，在这期间，I/O还能进行其他操作。如本节要介绍的select()函数，就是属于这种模型

//原来在实现双工通信的时候，需要等待标准输入再读取管道的数据,使用select可以实现当管道和标准输入
//任意一个出现数据的时候都能响应

//select函数
//用于等待一个或多个文件描述符上的I/O事件,允许程序同时监控多个I/O操作，从而可以同时处理多个输入，提高程序的效率
//int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
//参数解释：
//maxfd：最大的文件描述符（其值应该为最大的文件描述符字 + 1）
//readset：内核读操作的描述符字集合
//writeset：内核写操作的描述符字集合
//exceptionset：内核异常操作的描述符字集合
//timeout：等待描述符就绪需要多少时间。NULL代表永远等下去，一个固定值代表等待固定时间，0代表根本
//不等待，检查描述字之后立即返回

//1.创建fd_set
//2.设置合适的监听
//3.调用select函数，让进程阻塞
//4.当监听的fd中，有任何一个就绪，则select就绪
//5.把所有监听的fd都问一遍是否就绪(轮询)

//fd_set 文件描述符集合,是select函数的参数

//如何找到就绪的fd
//1.轮询
//2.回调

//如果一方关闭了聊天，另一方就会进入死循环
//说明select没有阻塞，管道一直就绪
//1.写端关闭，读端read读到EOF(就绪)
//2.read就绪引发select就绪
//解决方案
//读到EOF就退出循环

//使用标准输入结束聊天 ctrl + d

//如果读端关闭，但是写端继续写入东西，这会导致进程的崩溃,收到SIGPIPE信号

#include "func.h"

int main()
{
    int fdr = open("../project11/01.pipe", O_RDONLY);
    int fdw = open("../project11/02.pipe", O_WRONLY);
    printf("我是聊天一号机\n");
    char buf[128] = { 0 };
    fd_set rdset; // 创建监听集合
    while (1) {
        //为什么每过一个循环就要进行一次rdset的设置？因为在rdset作为select函数参数的时候，是一个传入传出参数，有可能在函数内部被修改
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







