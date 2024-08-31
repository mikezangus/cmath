#include "main.h"
#include <stdio.h>

static void init(void)
{
    flows.arithmetic = flows.alg_1var = 0;
}

int is_arithmetic(char *s)
{
    for (char *p = s; *p != '\0'; p++) {
        if (*p == 'x') {
            return 0;
        }
    }
    return flows.arithmetic = 1;
}

int is_algebraic(char *s)
{
    for (char *p = s; *p != '\0'; p++) {
        if (*p == 'x') {
            return flows.alg_1var = 1;
        }
    }
    return 0;
}

void set_workflow(char *s)
{
    init();
    if (is_arithmetic(s)) {
        ;;
    } else if (is_algebraic(s)) {
        ;;
    }
}
