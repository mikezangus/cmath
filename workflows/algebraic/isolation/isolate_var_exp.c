#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"

static bool extract_var_exp_oprtn(char* dst,
                                  char** start, char** end,
                                  const char* src)
{
    char* eq_sign = strchr(src, '=');
    if (!eq_sign) {
        return false;
    }
    *start = *end = NULL;
    char* p_dst = dst;
    for (const char* p_src = src, * var; p_src < eq_sign; p_src = var + 1) {
        var = find_var(p_src, strchr(src, '=') - 1);
        if (!var) {
            return false;
        }
        if (*(var + 1) != '^'
            || !isdigit(*(var + 2))
            || (*(var + 2) == 1 && isdigit(*(var + 3)))
            || get_paren_depth(var + 2, eq_sign) != -1) {
            continue;
        }
        *p_dst++ = '^';
        *p_dst++ = '1';
        *p_dst++ = '/';
        *start = (char*)(var + 1);
        *end = extract_num_fwd(p_dst, var + 2);
        return true;
    }
    return false;
}

void isolate_var_exp(char* s)
{
    char oprtn[STR_MAXLEN];
    char* start;
    char* end;
    while (true) {
        memset(oprtn, '\0', STR_MAXLEN);
        start = end = NULL;
        if (!extract_var_exp_oprtn(oprtn, &start, &end, s) || *oprtn == '\0') {
            break;
        }
        printf("Extracted exp string: %s\n", oprtn);
        collapse_str(start, end);
        insert_str(s, oprtn, s + strlen(s));

        enter_workflow(strchr(s, '=') + 1);
    }
}