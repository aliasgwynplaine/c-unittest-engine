#ifndef _UNITTEST_ENGINE_H
#define _UNITTEST_ENGINE_H

#include <stdio.h>

#ifdef assert
#undef assert
#endif

#define MAX_BUFF_SZ 512

#define assert(test, msg) do {                                                       \
    char * buff = malloc(sizeof(char) * MAX_BUFF_SZ);                                \
    if (!(test)) {                                                                   \
        snprintf(buff, MAX_BUFF_SZ, "[!] %s %d: %s\n", __FUNCTION__, __LINE__, msg); \
        return buff;                                                                 \
    }                                                                                \
} while (0)

#define run_uniitest(test) do {       \
    printf("Running %-50s", #test);   \
    char * msg = test(); tests_run++; \
    if (msg) {                        \
        failed_tests++;               \
        printf("%s\n", "[fail]");     \
        fprintf(stderr, "%s", msg);   \
        free(msg);                    \
    } else printf("%s\n", "[done]");  \
} while(0)

extern int tests_run;
extern int failed_tests;

#endif
