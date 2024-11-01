#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../../main.h"
#include "../../../utils/utils.h"

static void extract_num_oprtn(char* dst,
                              char** start, char** end,
                              const char* src)
{
    char* eq_sign = strchr(src, '=');
    if (!eq_sign) {
        return;
    }
    *start = *end = NULL;
    char* p_dst = dst;
    if (isdigit(*src)) {
        *p_dst++ = '-';
        *start = (char*)src;
        *end = extract_num_fwd(p_dst, src);
        return;
    }
    for (const char* p_src = src, * oprtr; p_src < eq_sign; p_src = oprtr + 1) {
        if (!(oprtr = find_oprtr(p_src, eq_sign - 1))) {
            break;
        }
        if (get_paren_depth(oprtr, eq_sign - 1) != 0) {
            continue;
        }
        *p_dst++ = invert_oprtr(*oprtr);
        *start = (char*)oprtr;
        *end = extract_num_fwd(p_dst, oprtr + 1);
        break;
    }
}

bool isolate_num_oprtn(char* s)
{
    char oprtn[STR_MAXLEN] = {0};
    char* start = NULL, * end = NULL;
    extract_num_oprtn(oprtn, &start, &end, s);
    if (*oprtn == '\0' || !start || !end) {
        return false;
    }
    collapse_str(start, end);
    insert_str(s, oprtn, s + strlen(s));
    return true;
}
