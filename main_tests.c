#include <stdio.h>
#include "unittest_engine.h"

int tests_run    = 0;
int failed_tests = 0;

static char *test_another_example() {
    assert(1 == 1, "Good !");
}

static char *test_example() {
    assert(1 != 1, "Missing tests!");
    return 0;
}

static void all_tests() {
    run_unittest(test_example);
    run_unittest(test_another_example);
}


int main(int argc, char * argv[]) {
    printf("Unit testing...\n\n");
    all_tests();
    printf("\nFailed %d from %d tests.\n", failed_tests, tests_run);

    return 0;
}
