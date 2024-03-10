#include "func.h"

//使用文件描述符形式的文件操作实现一个copy命令

 int main()
{
     char* filePath = "file.dat";
     char buf[128];
     int fd = open(filePath, O_RDWR); // 以读写的方式打开一个文件
     ERROR_CHECK(fd, -1, "open");
     int ret = read(fd, buf, sizeof(buf)); // 将文件中的1内容读取到buf字符数组中
     //    printf("%s\n", buf);
     int fd1 = open("end.dat", O_RDWR | O_CREAT);
     ERROR_CHECK(fd1, -1, "open");
     int ret1 = write(fd1, buf, strlen(buf)); // 将buf字符数组中的内容写入到文件中
     ERROR_CHECK(ret1, -1, "write");

    close(fd);
    close(fd1);
    return 0;
}

