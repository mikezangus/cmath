
#include "../utils/utils.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

static int find_i_sequence(char c, int *sw_paren, int *scale)
{
    if (!(*sw_paren) && (c == '(' || c == ')')) {
        *sw_paren = 1;
    }
    if (*sw_paren) {
        weigh_chars(c, scale, '(', ')');
    }
    if ((!(*scale) && !isdigit(c) && c != 'x')) {
        return 1;
    }
    return 0;
}

static int find_i_l(char *s, int i_op)
{
    int sw_paren = 0;
    int scale = 0;
    int i = -1;
    for (i = i_op - 1; s[i] > 0; i--) {
        if (i == 0) {
            return i;
        } else if (find_i_sequence(s[i], &sw_paren, &scale)) {
            return i + 1;
        }
    }
    return -1;
}

static int find_i_r(char *s, int i_op)
{
    int len = strlen(s) - 1;
    int sw_paren = 0;
    int scale = 0;
    int i = -1;
    for (i = i_op + 1; s[i] != '\0' && i <= len; i++) {
        if (i == len || find_i_sequence(s[i], &sw_paren, &scale)) {
            return i;
        }
    }
    return -1;
}

static int in_parens(char *s, int i_op)
{
    char *p;
    for (p = s + i_op - 1; p >= s && (isdigit(*p) || *p == 'x'); p--) {
        ;;
    }
    int l = (*p == '(');
    if (!l) {
        return 0;
    }
    for (p = s + i_op + 1; *p != '\0' && (isdigit(*p) || *p == 'x'); p++) {
        ;;
    }
    int r = (*p == ')');
    return l && r;
}

static void insert_sequence(char *s, int i_op)
{
    insert_str(s, "(", find_i_l(s, i_op));
    insert_str(s, ")", find_i_r(s, i_op + 1));
}

static int process_vars(char *s, int *i_var, int (*is_oprtr)(char))
{
    if (is_oprtr(s[(*i_var) - 1]) && !in_parens(s, (*i_var) - 1)) {
        insert_sequence(s, (*i_var) - 1);
        (*i_var) += 2;
        return 1;
    } else if (is_oprtr(s[(*i_var) + 1]) && !in_parens(s, (*i_var) + 1)) {
        insert_sequence(s, (*i_var) + 1);
        (*i_var) += 2;
        return 1;
    }
    return 0;
}

static void handle_vars(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'x' && (
            process_vars(s, &i, is_prec1_oprtr) ||
            process_vars(s, &i, is_prec2_oprtr)
        )) { ;; }
    }
}

static void process_nums(char *s, int *i_op, int (*is_oprtr)(char))
{
    if (is_oprtr(s[*i_op]) && !in_parens(s, *i_op)) {
        insert_sequence(s, *i_op);
        (*i_op += 2);
    }
}

static void handle_nums(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        process_nums(s, &i, is_prec1_oprtr);
    }
    for (i = 0; s[i] != '\0'; i++) {
        process_nums(s, &i, is_prec2_oprtr);
    }
}

void insert_parens(char *s)
{
    handle_vars(s);
    handle_nums(s);
}
