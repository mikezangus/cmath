#include <ctype.h>
#include <string.h>
#include "main.h"
#include "./utils/utils.h"

static int find_first_digit(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            return i;
        }
    }
    return -1;
}

static int find_last_digit(void)
{
    int len = strlen(input);
    for (int i = len; i > 0; i--) {
        if (isdigit(input[i])) {
            return i;
        }
    }
    return -1;
}

static int check_if_multiple_ops(void)
{
    int start;
    if (sw.parens_exist) {
        start = parens.l + 2;
    } else {
        start = 1;
    }
    int cnt = 0;
    for (int i = start; input[i] != ')' && input[i] != '\0'; i++) {
        if (is_oprtr(input[i])) {
            cnt++;
            if (cnt == 2) {
                return i;
            }
        }
    }
    return 0;
}

void find_bounds(void)
{
    int i_op2 = check_if_multiple_ops();
    if (i_op2) {
        bounds.r = i_op2 - 1;
    }
    if (sw.parens_exist) {
        bounds.l = parens.l + 1;
        if (!i_op2) {
            bounds.r = parens.r - 1;
        }
    } else if (!sw.parens_exist) {
        bounds.l = find_first_digit();
        if (!i_op2) {
            bounds.r = find_last_digit();
        }
    }
}
