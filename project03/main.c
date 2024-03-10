#include "func.h"

//实现ls -l

int main()
{
    char* filePath = ".";   //文件路径
    DIR* dirp = opendir("."); // 打开当前目录
    ERROR_CHECK(dirp, NULL, "opendir");
    struct dirent* pdirent;
    struct stat statbuf;
    chdir(filePath);        //前往文件路径指定的目录
    while (pdirent = readdir(dirp)) {
        int ret = stat(pdirent->d_name, &statbuf); // 用缓冲区statbuf来接收文件信息
        struct tm* p = NULL;
        p = localtime(&statbuf.st_mtime);
        printf("%6o %ld %d %s %8ld   %d/%d/%d %d:%d:%2d   %s\n", statbuf.st_mode, statbuf.st_nlink,
            getpwuid(statbuf.st_uid)->pw_name, getgrgid(statbuf.st_gid)->gr_name,
            statbuf.st_size, p->tm_year + 1900, p->tm_mon + 1, p->tm_mday, p->tm_hour,
            p->tm_min, p->tm_sec, pdirent->d_name);
    }

    return 0;
}
