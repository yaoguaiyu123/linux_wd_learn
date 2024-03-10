#include "func.h"

//实现递归遍历文件
//tree状遍历文件

void DFSdir(char *path,int width);

int main()
{
    char* filePath = "."; // 指定当前目录为要打开的目录
    DFSdir(filePath, 0);
    return 0;
}


void DFSdir(char* path, int width)
{
    // 深搜遍历文件夹
    DIR* pdir = opendir(path); // 打开一个文件夹
    ERROR_CHECK(pdir, NULL, "opendir");
    struct dirent* pdirent;
    char buf[1024];
    char newPath[1024];
    while (pdirent = readdir(pdir)) { // 循环读取打开的文件夹中的内容
        if (strcmp(pdirent->d_name, ".") == 0 || strcmp(pdirent->d_name, "..") == 0) {
            continue; // 遇到 .  和  .. 就跳过
        }
        for (int i = 0; i < width - 4; ++i) {
            printf(" ");
        }
        printf("|");
        for (int i = 0; i < 3; ++i) {
            printf("-");
        }
        printf("%s\n", pdirent->d_name);
        if (pdirent->d_type == DT_DIR) {
            // 如果是文件夹的类型就递归打开
            sprintf(newPath, "%s%s%s", path, "/", pdirent->d_name);
            DFSdir(newPath,width + 4);
        }
    }
}
