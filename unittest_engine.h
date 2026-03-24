#ifndef _UNITTEST_ENGINE_H
#define _UNITTEST_ENGINE_H

#include <stdio.h>
#include <stdlib.h>

#ifdef assert
#undef assert
#endif

#define assert(test, msg) do {                                                       \
	if (!(test)) {                                                                   \
		int len = snprintf(NULL, 0, "[!] %s %d: %s\n", __FUNCTION__, __LINE__, msg); \
		char *buff = malloc(sizeof(char) * len);                                     \
		return buff;                                                                 \
	}                                                                                \
} while (0)

#define run_unittest(test) do {       \
	printf("Running %-50s", #test);   \
	char *msg = test(); tests_run++;  \
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
