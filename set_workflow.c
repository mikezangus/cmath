#include "main.h"

static void init(void)
{
    sw.arithmetic = sw.alg_1var = 0;
}

int is_arithmetic(void)
{
    for (char *p = input; *p != '\0'; p++) {
        if (*p == 'x') {
            return 0;
        }
    }
    return 1;
}

int is_algebraic(void)
{
    for (char *p = input; *p != '\0'; p++) {
        if (*p == 'x') {
            return 1;
        }
    }
    return 0;
}

void set_workflow(void)
{
    init();
    if (is_arithmetic()) {
        sw.arithmetic = 1;
        return;
    } else if (is_algebraic()) {
        sw.alg_1var = 1;
        return;
    }
}
