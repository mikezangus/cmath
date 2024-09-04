#include <ctype.h>
#include <string.h>
#include "../utils/utils.h"
#include "../main.h"
#include <stdio.h>

static int find_i_oprtr(char *s, int prec)
{
    int i = (*s == '-') ? 1 : 0;
    int (*is_oprtr)(char) = NULL;
    switch (prec) {
        case 1:
            is_oprtr = is_prec1_oprtr;
            break;
        case 2:
            is_oprtr = is_prec2_oprtr;
            break;
        case 3:
            is_oprtr = is_prec3_oprtr;
            break;
        default:
            return -1;
    }
    for (; s[i] != '\0'; i++) {
        if (is_oprtr(s[i])) {
            if (prec == 1 && s[i - 1] == 'x') {
                sw.sw_var_exp = 1;
                return -1;
            }
            return i;
        }
    }
    return -1;
}

static int conditions(char c)
{
    if (sw.sw_var_exp) {
        return (isdigit(c) || c == '^' || c == '/' || c == 'x');
    }
    return (isdigit(c) || c == '/' || c == 'x');
}

static int find_i_l_bound(char *s, int i_oprtr)
{
    int i;
    for (i = i_oprtr - 1; i >= 0 && conditions(s[i]); i--) {
        ;;
    }
    return i == 0 && *s == '-' ? i : i + 1;
}

static int find_i_r_bound(char *s, int i_oprtr)
{
    int i;
    for (i = i_oprtr + 1; s[i] != '\0' && conditions(s[i]); i++) {
        ;;
    }
    return i - 1;
}

static void find_closest_parens(char *s, int *l_bound, int *r_bound)
{
    int l;
    int r;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            l = i;
        } else if (s[i] == ')') {
            r = i;
            break;
        }
    }
    *l_bound = l + 1;
    *r_bound = r - 1;
}

static void find_highest_oprtr(char *s, int *l_bound, int *r_bound)
{
    int i_oprtr;
    for (int i = 1; i <= 3; i++) {
        if ((i_oprtr = find_i_oprtr(s, i)) > -1) {
            break;
        }
    }
    *l_bound = find_i_l_bound(s, i_oprtr);
    *r_bound = find_i_r_bound(s, i_oprtr);
}

void find_bounds(char *s, int *l_bound, int *r_bound)
{
    if (strchr(s, '(')) {
        find_closest_parens(s, l_bound, r_bound);
    } else {
        find_highest_oprtr(s, l_bound, r_bound);
    }
    print_str("Finding bounds:", s);
    printf("Bounds - L: %d | R: %d\n", *l_bound, *r_bound);
}
