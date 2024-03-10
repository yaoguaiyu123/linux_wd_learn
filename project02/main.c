#include "func.h"

void test01(int argc, char* argv[])
{
    // 修改文件权限

    ARGC_CHECK(argc, 3);
    mode_t mode; // mode用于存储文件的访问权限信息,文件和目录的权限可以使用三个八进制数字来表示
    sscanf(argv[1], "%o", &mode); // 将777作为八进制数存储到mode
    int ret = chmod(argv[2], mode);
    ERROR_CHECK(ret, -1, "chmod");
}

void test02()
{
    // getcwd 相当于 pwd
    char buf[1024] = { 0 };
    char* ret = getcwd(buf, sizeof(buf)); // 当buf数组太小，导致执行失败,就会返回空指针
    ERROR_CHECK(ret, NULL, "getcwd");
    printf("ret=%p,ret=%s\n", ret, ret); // 打印ret指针地址值 和 ret指针指向的内容
    printf("buf=%p,buf=%s\n", buf, buf);
}

void test03()
{
    // chdir  修改当前工作目录
    // 进入原本工作目录下的tmp目录
    chdir("/run/media/root/study/SystemProgram/01/build-project02-C_C_2023_11_04-Debug/tmp");
    char* ret = getcwd(NULL, 0);
    printf("当前工作目录:%s\n", ret);
    free(ret);
}

void test04()
{
    // mkdir 创建目录
    // rmdir 删除目录
    // 第二个参数代表目录的权限，需要传入三位8进制数字
    int ret1 = mkdir("/run/media/root/study/SystemProgram/01/build-project02-C_C_2023_11_04-Debug/tmp01", 0777);
    int ret2 = mkdir("/run/media/root/study/SystemProgram/01/build-project02-C_C_2023_11_04-Debug/tmp02", 0555);
    ERROR_CHECK(ret1, -1, "mkdir");
    ERROR_CHECK(ret2, -1, "mkdir");
    int ret3 = rmdir("/run/media/root/study/SystemProgram/01/build-project02-C_C_2023_11_04-Debug/tmp01");
    ERROR_CHECK(ret3, -1, "rmdir");
}

void test05()
{
    // 类似ls命令的实现
    DIR* dir = opendir("."); // 打开当前目录
    ERROR_CHECK(dir, NULL, "opendir");
    struct dirent* dirt;
    // 目录中的每一个文件/子目录作为一个dirent结点,以链式的形式存储
    // readdir函数在读取目录中当前文件的同时也会修改当前的偏移，使当前的偏移指向下一个文件(dirent结点)
    long int location;
    while ((dirt = readdir(dir)) != NULL) {
        // 通过循环遍历所有目录中的文件
        if (strcmp(dirt->d_name, "tmp02") == 0) {
            location = telldir(dir);
        }

        printf("inode = %ld,reclen = %d,type = %d,name = %s\n", dirt->d_ino, dirt->d_reclen, dirt->d_type, dirt->d_name);
        //        printf("%ld\n", dirt->d_off);
    }
    // 读完之后想找到某个结点(方法1)
    // 1.telldir获取location
    // 2.seeckdir回到该结点 ,这种方法需要先telldir再readdir,否则会一直找到下一个结点
    //    seekdir(dir, location);
    //    struct dirent* pdirent = readdir(dir);
    //    printf("-----------------------------------\n");
    //    printf("此时的name:%s\n",pdirent->d_name);


    // 读完之后想找到某个结点(方法2)
    // rewinddir
    rewinddir(dir);     //偏移量回到最开始
    struct dirent* pdirent = readdir(dir);
    printf("-------------------------------------------------\n");
    printf("此时的name:%s\n",pdirent->d_name);

    int ret = closedir(dir);
    ERROR_CHECK(ret, -1, "closedir");
}

int main(int argc, char* argv[])
{
    //    test02();
    //    test03();
    //    test04();
    test05();
    return 0;
}
