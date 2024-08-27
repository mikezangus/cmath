#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"

int find_mult_oprtr(int start)
{
    for (int i = start; input[i] != '\0'; i++) {
        if (input[i] == '*') {
            printf("Mult operator found: input[%d] = %c\n", i, input[i]);
            return i;
        }
    }
    return -1;
}

int find_i_l_paren(int start)
{
    int op1_found = 0;
    for (int i = start - 1; i >= 0; i--) {
        if (is_oprtr(input[i]) && !is_prec1_oprtr(input[i]) && !op1_found) {
            op1_found = 1;
        } else if (is_oprtr(input[i]) && !is_prec1_oprtr(input[i]) && op1_found) {
            return i + 1;
        }
    }
    return -1;
}

int find_i_r_paren(int start)
{
    int op1_found = 0;
    int len = strlen(input) - 1;
    for (int i = start + 1; input[i] != '\0' && i <= len; i++) {
        if (i == len) {
            return i + 1;
        } else if (is_oprtr(input[i]) && !op1_found) {
            op1_found = 1;
        } else if (is_oprtr(input[i]) && op1_found) {
            return i - 1;
        }
    }
    return -1;
}

void insert_paren(int *i, char *p, int i_p)
{
    expand_str(input, " ", i_p);
    input[i_p] = *p;
    (*i)++;
}

void add_parens_div(void)
{
    int i_mult_oprtr;
    int i_l_paren;
    int i_r_paren;
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if ((i_mult_oprtr = find_mult_oprtr(i)) > -1) {
            i_l_paren = i_r_paren = -1;
            i = i_mult_oprtr;
            if ((i_l_paren = find_i_l_paren(i)) > -1) {
                insert_paren(&i, "(", i_l_paren);
            } else {
                break;
            }
            if ((i_r_paren = find_i_r_paren(i)) > -1) {
                insert_paren(&i, ")", i_r_paren);
            } else {
                break;
            }
        } else {
            break;
        }
    }
}
