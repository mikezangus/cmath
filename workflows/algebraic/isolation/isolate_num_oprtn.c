#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"

static bool extract_num_oprtn(char* dst,
                              char** start, char** end,
                              const char* src)
{
    char* eq_sign = strchr(src, '=');
    if (!eq_sign) {
        return false;
    }
    *start = *end = NULL;
    char* p_dst = dst;
    if (isdigit(*src)) {
        *p_dst++ = '-';
        *start = (char*)src;
        *end = extract_num_fwd(p_dst, src);
        return true;
    }
    for (const char* p_src = src, * oprtr; p_src < eq_sign; p_src = oprtr + 1) {
        if (!(oprtr = find_oprtr(p_src, eq_sign - 1))) {
            return false;
        }
        if (get_paren_depth(oprtr, eq_sign - 1) != 0) {
            continue;
        }
        *p_dst++ = invert_oprtr(*oprtr);
        *start = (char*)oprtr;
        *end = extract_num_fwd(p_dst, oprtr + 1);
        return true;
    }
    return false;
}

void isolate_num_oprtn(char* s)
{
    char oprtn[STR_MAXLEN];
    char* start;
    char* end;
    while (true) {
        memset(oprtn, '\0', STR_MAXLEN);
        start = end = NULL;
        if (!extract_num_oprtn(oprtn, &start, &end, s)
            || *oprtn == '\0'
            || !start
            || !end) {
            break;
        }
        collapse_str(start, end);
        insert_str(s, oprtn, s + strlen(s));
        enter_workflow(strchr(s, '=') + 1);
    }
}
