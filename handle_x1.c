#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "header.h"

extern char input[];

static void collapse_str(int pos)
{
    for (int i = pos - 1; input[i] != '\0'; i++) {
        input[i] = input[i + 2];
    }
    printf("Handled 1*x: %s\n", input);
}

static bool check_conds(int pos)
{
    if (input[pos - 1] != '1') {
        return false;
    }
    if (pos - 1 == 0) {
        return true;
    }
    if (isdigit(input[pos - 2])) {
        return false;
    }
    return true;
}

bool handle_x1(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '*') {
            if (check_conds(i)) {
                collapse_str(i);
                return true;
            }
        }
    }
    return false;
}
