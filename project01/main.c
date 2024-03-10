#include "func.h"

// 系统编程

// argc 表示命令行参数的个数，它是一个整数类型的变量。在不传递任何命令行参数的情况下，
// argc 的值为1，表示只有程序名称本身作为一个参数。
// argv 则是一个数组，它包含了传递给程序的命令行参数。它是一个字符串数组，每个元素存储一个命令行参数。
// 第一个参数 argv[0] 存储的是程序运行的完整路径名或者可执行文件名，之后的参数则从 argv[1] 开始存储。

int main(int argc, char* argv[])
{
    ARGC_CHECK(argc, 2);
    // a模式是只写的，a+模式可以读写
    //    FILE* fp = fopen(argv[1], "a");       //以追加的方式打开文件
    //    ERROR_CHECK(fp, NULL, "fopen");
    //    fwrite("howareyou", 1, 9, fp);     //每个元素的大小为1个字节,总共有9个元素

    FILE* fp = fopen(argv[1], "a+");
    ERROR_CHECK(fp, NULL, "fopen");
    char buf[12] = { 0 };
    fread(buf, 1, 9, fp); // 将数据从文件中读到buf
    puts(buf); // 可以读到数据
    printf("文件读写指针的位置:%ld\n", ftell(fp));
    fseek(fp, 0, SEEK_SET);      //将文件的读写指针指向文件开头
    printf("文件读写指针的位置:%ld\n", ftell(fp));
    fwrite("WWW", 1, 9, fp);    //成功写入数据,写入时跳到文件的末尾进行写入
    printf("文件读写指针的位置:%ld\n", ftell(fp));
    fclose(fp);

    return 0;
}
