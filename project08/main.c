#include "func.h"

//进程
void test01()
{
    // 使用系统调用创建一个进程
    // system
    printf("我要去睡觉了");
    sleep(10); // 休眠10s
}

void test02()
{
    // 使用fork函数复制当前的进程
    pid_t pid;
    pid = fork();
    printf("执行完毕,pid = %d\n", pid);
    if (pid == 0) {
        printf("这是通过fork复制出来的子进程\n");
    } else {
        printf("这是父进程\n");
    }
    printf("\n");
}

int global = 1;

void test03()
{
    // fork的底层原理
    // 1.fork会拷贝一份task_struct
    // 2.子进程修改一些必要的数据
    // 3.子进程加入到就绪队列
    // 1,2过程之中不可抢占，时间短

    // 用户态的数据是拷贝的
    int stack = 2;
    int* pheap = (int*)malloc(sizeof(int));
    *pheap = 3;
    if (fork() == 0) {
        printf("我是子进程,当前的值为global = %d,stack = %d,*pheap = %d\n", global, stack, *pheap);
        global++;
        stack++;
        (*pheap)++;
        printf("我是子进程,当前的值为global = %d,stack = %d,*pheap = %d\n", global, stack, *pheap);

    } else {
        sleep(5);
        printf("我是父进程,当前的值为global = %d,stack = %d,*pheap = %d\n", global, stack, *pheap);
    }
    // 可以看到父子进程的数据是拷贝的，而非共享的,也就是说子进程的数据的更改不会影响到父进程的数据的值
}

void test04()
{
    // printf的本质：往stdout缓冲区中写入内容，如果stdout中遇到换行符或者满或者刷新，就将内容显示到屏幕上
    // 当执行fork的时候，将会拷贝stdout中的内容(stdout在用户态),因此两个进程各有一份hello的数据在stdout缓冲区中
    printf("hello");
    fork();
    printf("world\n");
}

void test05()
{
    int fd = open("../project08/file1.dat", O_RDWR);
    ERROR_CHECK(fd, -1, "open");
    if (fork() == 0) {
        write(fd, "hello", 5);
        printf("子进程写入完毕\n");
    } else {
        sleep(3);
        write(fd, "world", 5);
        printf("父进程写入完毕\n");
    }
    // 可以看到文件描述符打开的文件中写入了helloworld,意味着父子进程共享了文件的偏移量
    // 对于内核态的文件，是共享的
}

void test06()
{
    for (int i = 0; i < 2; ++i) {
        fork();
        printf("-");
    }
    // 一共打印8个'-'
}

void test07()
{
    // exec函数族
    // execl 将当前的数据清空,
    printf("执行exec之前\n");
    printf("pid = %d\n", getpid());
    //    execl("add", "./add", NULL);
    char* argvector[] = { "./add", "3", "4", NULL }; // 创建一个字符串数组，作为参数传入给execv
    execv("add", argvector);
    printf("执行exec之后\n");
    // 在两个不同的可执行文件中的pid是一样的，说明这是同一个进程
}

void splitStr()
{
    // 这里实现分割一个字符串
    char sentence[] = "hello world jie";
    char* word;
    word = strtok(sentence, " "); // 使用strtok函数分割字符串，传入" "作为分隔符
    printf("word = %s\n", word);
    word = strtok(NULL, " ");
    printf("word = %s\n", word);
    word = strtok(NULL, " ");
    printf("word = %s\n", word);
    word = strtok(NULL, " ");
    printf("word = %s\n", word);
}

void test08()
{
    // 使用fork和exce实现system函数的功能
}

void test09_0()
{
    // 演示父进程先于子进程退出，导致子进程成为孤儿进程
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        sleep(1);
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        // 当父进程先于子进程退出，那么子进程的父进程都将被置为init进程

    } else {
        printf("我是一个父进程,我的pid是: %d\n", getpid());
    }
}

void test09()
{
    // wait函数
    // wait函数可以阻塞父进程，直到该父进程的一个子进程终止并返回信息
    // wait(NULL) 表示等待到任意一个子进程终止
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        sleep(1);
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());

    } else {
        printf("我是一个父进程,我的pid是: %d\n", getpid());
        wait(NULL); // 等待子进程终止
    }
}

void test10()
{
    // 如果子进程终止的时候，父进程一直不调用wait,则子进程成为僵尸进程:进程终止，但是资源没有回收
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        sleep(1);
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());

    } else {
        printf("我是一个父进程,我的pid是: %d\n", getpid());
        while (1) {
            // 父进程一直在这边循环
        }
    }
}

void test11()
{
    // 使用wait获取子进程退出时的信息
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        sleep(1);
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        //        while (1)
        //            ;
    } else {
        printf("我是一个父进程,我的pid是: %d\n", getpid());
        int waitStatus;
        wait(&waitStatus);
        if (WIFEXITED(waitStatus)) {
            printf("子进程正常退出,waitStatus = %d\n", waitStatus);
        } else if (WIFSIGNALED(waitStatus)) {
            printf("子进程异常退出,waitStatus = %d\n", waitStatus);
        }
    }
}

void test12()
{
    // waitpid函数，等待指定的子进程的退出
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
        sleep(1);
        printf("我是一个子进程,我的pid是: %d\n", getpid());
        printf("ppid=%d\n", getppid());
    } else {
        printf("我是一个父进程,我的pid是: %d\n", getpid());
        int waitStatus;
        while (1) {
            int ret = waitpid(-1, &waitStatus, WNOHANG); //-1表示等待任何子进程，WNOHANG表示以非阻塞的形式等待子进程,如果没有子进程结束就返回0
            if (ret == 0) {
                printf("子进程还未结束\n");
                sleep(1);
            } else {
                if (WIFEXITED(waitStatus)) {
                    printf("子进程正常退出,waitStatus = %d\n", waitStatus);
                } else if (WIFSIGNALED(waitStatus)) {
                    printf("子进程异常退出,waitStatus = %d\n", waitStatus);
                }
                break;
            }
        }
    }
}

void test13()
{
    // 得到组id
    if (fork() == 0) {
        printf("我是一个子进程,pid = %d,pgid = %d\n", getpid(), getpgid(0));
        setpgid(0, 0);
        // 第一个0表示将当前进程的进程ID作为进程组ID。
        // 第二个0表示表示将当前进程的进程组ID设置为与其进程ID相同
        printf("我是一个子进程,pid = %d,pgid = %d\n", getpid(), getpgid(0));

    } else {
        printf("我是一个父进程,pid = %d,pgid = %d\n", getpid(), getpgid(0)); // getpgid(0)表示当前进程的pgid
        wait(NULL);
    }
}

void test14()
{
    // 会话session
    // session是进程组的集合
    printf("sid = %d\n", getsid(0)); // 返回当前进程的会话id
}

void test15()
{
    if (fork() != 0) {
        int fd = open("infor.dat", O_RDWR);
        write(fd, "fjcdcyy", 7);
        exit(0); // 如果是父进程就退出
    }
    printf("子进程的pid = %d\n", getpid());
    // 父进程退出之后子进程成为孤儿进程，其新的父进程为init进程
    setsid(); // 创建一个新的会话
    for (int i = 0; i < 2; ++i) {
        close(i);
    }
    chdir("/");
    umask(0);
    // 守护线程执行的任务
    int fd = open("/root/infor.dat", O_RDWR);
    for (int i = 0; i < 10; ++i) {
        write(fd, "nihao\n", 6);
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
    //    splitStr();
    //    test08();
    //    test09_0();
    //    test09();
    //    test10();
    //    test11();
    //    test12();
    //    test13();
    //    test14();
    test15();
    return 0;
}
