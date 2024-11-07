#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"

static bool extract_base_oprtn(char* dst,
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
        var = find_var(p_src + 1, strchr(src, '=') - 1);
        if (!var) {
            return false;
        }
        if (!isdigit(*(var - 1)) || get_paren_depth(var, eq_sign - 1) != -1) {
            continue;
        }
        *p_dst++ = '/';
        *start = extract_num_bwd(p_dst, var - 1, src);
        *end = (char*)(var - 1);
        return true;
    }
    return false;
}

bool isolate_var_base(char* s)
{
    char oprtn[STR_MAXLEN] = {0};
    char* start = NULL, * end = NULL;
    if (!extract_base_oprtn(oprtn, &start, &end, s) || *oprtn == '\0') {
        return false;
    }
    collapse_str(start, end);
    insert_str(s, oprtn, s + strlen(s));
    return true;
}
