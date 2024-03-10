#include "func.h"
    
int main(){
    char *pipeName1 = "1.pipe";
    char *pipeName2 = "2.pipe";
    int fdr = open(pipeName1,O_RDONLY);
    int fdw = open(pipeName2,O_WRONLY);
    puts("pipe open!");
    char buf[4096]={0};
    fd_set rdset;    //创建一个监听集合
    while(1)
    {
        struct timeval timeout;
        timeout.tv_sec=2;     //设置秒
        timeout.tv_usec=500000;    //设置微秒
        FD_ZERO(&rdset);     //清空集合中的所有监听
        FD_SET(STDIN_FILENO,&rdset);   //新增一个监听,监听标准输入
        FD_SET(fdr,&rdset);        //新增一个监听，监听管道
        int sret = select(fdr+1,&rdset,NULL,NULL,&timeout);     //阻塞进程，只有当任意监听的fd就绪时，select才就绪
        if (sret ==0){
            puts("time_out");
            continue;
        }
        if(FD_ISSET(fdr,&rdset)){
            memset(buf,0,sizeof(buf));
            int ret = read(fdr,buf,sizeof(buf));
            if(ret==0){
                printf("对方结束聊天\n");
                break;
            }
            puts(buf);
        }else if(FD_ISSET(STDIN_FILENO,&rdset)){
            memset(buf,0,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            if(ret==0){
                write(fdw,"我将结束聊天\n",sizeof("我将结束聊天\n"));
                break;
            }
            write(fdw,buf,strlen(buf));
        }
       

    }
    return 0;
}
    
