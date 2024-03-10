#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>     //linux独有的头文件
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
int main(){
    int a =1;
    int b =2;
    printf("a+b=%d\n",a+b);
    printf("pid = %d\n", getpid());
    return 0;
}
