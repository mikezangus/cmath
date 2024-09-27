#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../../main.h"
#include "../../utils/utils.h"

static char* find_insert_pos(char* s)
{
    bool var_found = false;
    for (char* p = s; *p; p++) {
        if (!var_found && is_var(*p)) {
            var_found = true;
        } else if (var_found && *p == ')') {
            return p + 1;
        }
    }
    return NULL;
}

static bool find_bounds(char* s, char** extract_start, char** extract_end)
{
    char* l_paren = NULL;
    char* r_paren = NULL;
    short scale = 0;
    for (char* p = s; *p && *p != '='; p++) {
        balance_chars(*p, &scale, '(', ')');
        if (scale < 0 && l_paren && r_paren) {
            *extract_start = l_paren - 1;
            *extract_end = r_paren;
            return true;
        }
        if (*p == '(') {
            l_paren = p;
        } else if (*p == ')') {
            r_paren = p;
        }
    }
    if (!l_paren || !r_paren) {
        return false;
    }
    *extract_start = l_paren - 1;
    *extract_end = r_paren;
    return true;
}

void extract_to_buff(char* buff, char* extract_start, char* extract_end)
{
    size_t len = extract_end - extract_start + 1;
    memcpy(buff, extract_start, len);
    buff[len] = '\0';
}

bool rearrange(char* s)
{
    char* p = s;
    while (*p && *p != '=') {
        char* insert_pos = NULL;
        char* extract_start = NULL;
        char* extract_end = NULL;
        char buff[STR_MAXLEN] = {0};
        if (!(insert_pos = find_insert_pos(p))) {
            return false;
        }
        if (!(find_bounds(insert_pos, &extract_start, &extract_end))) {
            return false;
        }
        extract_to_buff(buff, extract_start, extract_end);
        collapse_str(extract_start, extract_end);
        insert_str(s, buff, insert_pos);
        p = insert_pos + strlen(buff);
    }
    return true;
}
