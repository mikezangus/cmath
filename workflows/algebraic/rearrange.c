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

static bool find_bounds(char* s, char** l_bound, char** r_bound)
{
    char* l_paren = NULL;
    char* r_paren = NULL;
    short scale = 0;
    for (char* p = s; *p && *p != '='; p++) {
        balance_chars(*p, &scale, '(', ')');
        if (scale < 0 && l_paren && r_paren) {
            *l_bound = l_paren - 1;
            *r_bound = r_paren;
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
    *l_bound = l_paren - 1;
    *r_bound = r_paren;
    return true;
}

void extract_to_buff(char* buff, char* l_bound, char* r_bound)
{
    for (char* p = l_bound; *p && p <= r_bound; p++, buff++) {
        *buff = *p;
    }
    *buff = '\0';
}

bool rearrange(char* s)
{
    char* p = s;
    while (*p && *p != '=') {
        char* insert_pos = NULL;
        char* l_bound = NULL;
        char* r_bound = NULL;
        char buff[STR_MAXLEN] = {0};
        if (!(insert_pos = find_insert_pos(p))) {
            return false;
        }
        if (!(find_bounds(insert_pos, &l_bound, &r_bound))) {
            return false;
        }
        extract_to_buff(buff, l_bound, r_bound);
        collapse_str(l_bound, r_bound);
        insert_str(s, buff, insert_pos);
        p = insert_pos + strlen(buff);
    }
    return true;
}
