#include "func.h"
#include <errno.h>
#include <string.h>

int main(){
    char *pipeName1 = "1.pipe";
    char *pipeName2 = "2.pipe";
    int fdw = open(pipeName1,O_WRONLY);
    int fdr = open(pipeName2,O_RDONLY);
    puts("pipe open!");
    char buf[4096]={0};
    fd_set rdset;    //创建一个监听集合
    while(1)
    {
        
    }
    return 0;
}
     
