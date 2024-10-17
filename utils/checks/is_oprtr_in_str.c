#include <ctype.h>
#include <stdbool.h>

static bool div_and_exp_oprtrs(char p, int* div_cnt, int* exp_cnt)
{
    if (p == '/') {
        (*div_cnt)++;
    } else if (p == '^') {
        (*exp_cnt)++;
    } else {
        return false;
    }
    if (*div_cnt > 1 || *exp_cnt > 1) {
        return true;
    }
    return false;
}

static bool sub_oprtr(char* p, char* s)
{
    if (*p != '-') {
        return false;
    }
    if (p == s) {
        return false;
    }
    char prev = *(p - 1);
    if (!isdigit(prev) && prev != ')') {
        return false;
    }
    char post = *(p + 1);
    if (!isdigit(post) && post != '(') {
        return false;
    }
    return true;
}

bool is_oprtr_in_str(char* s)
{
    int div_cnt = 0;
    int exp_cnt = 0;
    for (char* p = s; *p; p++) {
        if (*p == '+' || *p == '*'
            || div_and_exp_oprtrs(*p, &div_cnt, &exp_cnt)
            || sub_oprtr(p, s)) {
            return true;
        }
    }
    return false;
}
