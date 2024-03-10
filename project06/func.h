#ifndef FUNC_H

#define FUNC_H

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

#define ARGC_CHECK(argc, num)                \
{                                        \
        if (argc != num) {                   \
            fprintf(stderr, "argc error\n"); \
            return -1;                       \
    }                                    \
}

#define ERROR_CHECK(ret, num, msg) \
{                              \
        if (ret == num) {          \
            perror(msg);           \
            return -1;             \
    }                          \
}

#endif // FUNC_H
