#include "func.h"

// mmap文件映射的使用
// 用户态和内核态就是访问的权限的不同
// 简单来说，用户态包括shell,库函数
// 内核态包括系统调用,内核功能(进程，内存,网络，文件)，驱动
// 之前的 read 和 write 函数就是直接打通了用户态和内核态，使用户能够直接访问和操作文件
// 这里的 mmap函数就是直接在用户态的内存空间中选择一块内存作为内核态中的文件的映射，这样也能做到访问和操作文件

void test01()
{
    char* filePath = "infor.dat";
    int fd = open(filePath, O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    int ret = ftruncate(fd, 10); // 将当前文件截断为10个字节
    ERROR_CHECK(ret, -1, "ftruncate");
    char* p = (char*)mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    for (int i = 0; i < 10; ++i) {
        printf("%c", p[i]);
    }
    printf("\n");
    p[2] = 'B'; // 这边直接修改用户态的内存，可以看到文件中的内容也被修改了
    for (int i = 0; i < 10; ++i) {
        printf("%c", p[i]);
    }
    printf("\n");
    close(fd);
}

void test02()
{
    // lseek的使用
    char* filePath = "test.dat";
    int fd = open(filePath, O_RDWR | O_CREAT);
    ERROR_CHECK(fd, -1, "open");
    lseek(fd, 1024, SEEK_SET); // 将当前的文件指针的偏移量设置为1024
    write(fd, "A", 1); // 写入一个字符
    close(fd);
    // 可以看到创建了一个文件，这个文件的大小为1025个字节
}


void test03()
{
    // 证明缓冲文件流的底层也使用了文件对象
    char* filePath = "test.dat";
    FILE* fp = fopen(filePath, "r+");
    ERROR_CHECK(fp, NULL, "fopen"); // 这里创建了一个文件对象
    //    int fileNo = fp->_fileno;               // 获取文件描述符
    int fileNo = fileno(fp); // 获取文件描述符(用接口的方法获取)
    int ret = write(fileNo, "helloworld", 10);
    //    int ret = write(3, "hello", 5);    //以文件描述符的方式打开写入文件，猜测文件描述符是3
    ERROR_CHECK(ret, -1, "write");
    fclose(fp);
}

void test04()
{
    // 显示默认创建的三个流对应的文件对象
    printf("stdin  fd = %d\n", fileno(stdin));
    printf("stdout fd = %d\n", fileno(stdout));
    printf("stderr fd = %d\n", fileno(stderr));
    // write(1, "hello world!!!\n", 16);     //直接往标准输出写入数据
    write(STDOUT_FILENO, "hello world!!!\n", 16);
}

void test05()
{
    // 使标准 printf 失效, 将其重定向到文件
    printf("you can see me!\n");
    close(STDOUT_FILENO); // 关闭标准输出
    int fd = open("printf.dat", O_RDWR); // 打开一个新的文件
    printf("fd of printf.dat = %d\n", fd);
    printf("you can not see me!\n");
}

void test06()
{
    // 文件描述符的复制 dup使用
    // 底层:文件描述符维护一个文件对象，而文件描述符符的复制就是让多个描述符维护同一个文件对象
    // 当一个文件描述符 close(fd),只是这个描述符不再维护文件对象，文件对象只有在所有的文件描述符都不再维护的时候才会释放
    int oldfd = open("file1", O_RDWR | O_CREAT);
    ERROR_CHECK(oldfd, -1, "open");
    int newfd = dup(oldfd); // 文件描述符的复制
    printf("newfd = %d\n", newfd);
    write(oldfd, "nihaoshijie", 11);
    write(newfd, "hello world", 11);
    // oldfd 和 newfd 是共享文件偏移的
    close(oldfd);
    write(newfd, "   okaxdm", 9); // 虽然关闭了oldfd,但是newfd可以继续写入,此时文件对象还有newfd在维护
}

void test07()
{
    // 使用dup进行重定向
    int oldfd = open("file2", O_RDWR | O_CREAT);
    ERROR_CHECK(oldfd, -1, "open");
    close(STDOUT_FILENO); // 关闭标准输出流文件
    int newfd = dup(oldfd); // 此时返回的newfd = 1
    printf("dddd\n"); // 此时的内容将会打印到file2文件中
}

void test08()
{
    // dup2使用,dup2多一个参数,可以指定newfd,如果newfd 已经有指向，就会自动close
    int oldfd = open("file3", O_RDWR | O_CREAT);
    ERROR_CHECK(oldfd, -1, "open");
    int newfd = dup2(oldfd, STDOUT_FILENO);      //将标准输出自动close,并且使newfd占用标准输出的文件描述符
    printf("hahaha\n");
}

void test09()
{
    // 管道
    // 读端
    // 管道是在open的时候阻塞的
    char* pipeName = "../project06/1.pipe";
    int fdr = open(pipeName, O_RDONLY); // 以读的形式打开管道
    ERROR_CHECK(fdr, -1, "open");
    char buf[128] = { 0 };
    read(fdr, buf, sizeof(buf)); // 从管道中读取数据
    printf("读到的数据:%s\n", buf);
    close(fdr);
}

void test10()
{
    // 管道
    // 写端
    char* pipeName = "../project06/1.pipe";
    int fdw = open(pipeName, O_WRONLY); // 以读的形式打开管道
    ERROR_CHECK(fdw, -1, "open");
    write(fdw, "nihaoshijie", 11); // 向管道中写入数据
    close(fdw);
}

void test11()
{
    // 写集合的原理
    // select函数监听写
    // 当管道中的内容太多的时候，写入操作就会进入阻塞态，当管道中的数据被读端接收之后，写端就可以恢复写入操作
    // 此时select函数就会监听到写入操作的就绪
    // 下面的程序中,每次写，写入4096,每次读，读出2048,到一个时间点之后，管道就会占用写缓冲区的内存
    // 此时写不再就绪，就会只进行读而不进行写，直到管道到达不满的状态
    int fdr = open("../project06/1.pipe", O_RDWR); //
    int fdw = open("../project06/1.pipe", O_RDWR);
    ERROR_CHECK(fdr, -1, "open");
    ERROR_CHECK(fdw, -1, "open");
    puts("pipe open\n");
    char buf[4096];
    fd_set rdset; // 创建一个监听集合，监听读
    fd_set wrset; // 创建一个监听结合，监听写
    int cnt = 0;
    while (1) {
        FD_ZERO(&rdset);
        FD_SET(fdr, &rdset); // 监听fdr
        FD_ZERO(&wrset);
        FD_SET(fdw, &wrset);
        select(fdw + 1, &rdset, &wrset, NULL, NULL);
        if (FD_ISSET(fdr, &rdset)) {
            printf("read cnt = %d\n",cnt++);
            read(fdr, buf, 2048); // 将数据从管道中读出来
        }
        if (FD_ISSET(fdw, &wrset)) {
            printf("write cnt = %d\n", cnt++);
            write(fdw, buf, 4096);    //将数据写入管道
        }
        sleep(1);
    }
}

int main()
{
    //    test01();
    //    test02();
    //    test03();
    //    test04();
    //    test05();
    //    test06();
    //    test07();
    //    test08();
    test11();
    return 0;
}









