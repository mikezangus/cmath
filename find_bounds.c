#include "header.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

extern char input[];
extern int l_bound;
extern int r_bound;
extern bool parens_exist;

int l_paren;
int r_paren;
int oprtr_cnt;
int oprtr_2_pos;

static void init(void)
{
    l_paren = r_paren = oprtr_2_pos = -1;
    oprtr_cnt = 0;
}

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

static void scan_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            l_paren = i;
        } else if (input[i] == ')') {
            r_paren = i;
            return;
        }
    }
}

static void count_oprtrs(void)
{
    int start = -1;
    if (parens_exist) {
        start = l_paren + 2;
    } else {
        start = 1;
    }
    for (int i = start; input[i] != ')'; i++) {
        if (is_oprtr(input[i])) {
            oprtr_cnt++;
            if (oprtr_cnt == 2) {
                oprtr_2_pos = i;
                return;
            }
        }
    }
}

void find_bounds(void)
{
    init();
    int first_digit = find_first_digit();
    int last_digit = find_last_digit();

    if (parens_exist == true) {
        scan_parens();
    }
    count_oprtrs();
    if (parens_exist) {
        l_bound = l_paren + 1;
        if (oprtr_cnt < 2) {
            r_bound = r_paren - 1;
        } 
    } else if (!parens_exist) {
        l_bound = first_digit;
        if (oprtr_cnt < 2) {
            r_bound = last_digit;
        } 
    }
    if (oprtr_cnt > 1) {
        r_bound = oprtr_2_pos - 1;
    }
}
