#include "func.h"
    
int main(){
    char *pipeName1 = "1.pipe";
    char *pipeName2 = "2.pipe";
    int fdr = open(pipeName1,O_RDONLY);
    int fdw = open(pipeName2,O_WRONLY);
    puts("pipe open!");
    char buf[4096]={0};
    fd_set rdset;    //创建一个监听集合
    int cnt = 0;
    
    while(1)
    {
        printf("count = %d\n",cnt++);
        write(fdw,buf,sizeof(buf));
    }
    return 0;
}
    
