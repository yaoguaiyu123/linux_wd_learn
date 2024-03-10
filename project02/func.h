#ifndef FUNC_H

#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>     //linux独有的头文件
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#define ARGC_CHECK(argc, num)                \
{                                        \
        if (argc != num) {                   \
            fprintf(stderr, "argc error\n"); \
            return;                       \
    }                                    \
}

#define ERROR_CHECK(ret, num, msg) \
{                              \
        if (ret == num) {          \
            perror(msg);           \
            return;             \
    }                          \
}

#endif // FUNC_H
