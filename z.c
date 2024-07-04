#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char input[100] = "1*2+3*4+4*5^6*7+8";
int len;
int l_oprtr_pos = 0;
int r_oprtr_pos = 0;

bool is_paren(char c)
{
    return c == '(' || c == ')';
}
bool is_exp_oprtr(char c)
{
    return c == '^';
}
bool is_m_or_d_oprtr(char c)
{
    return c == '*' || c == '/';
}
bool is_oprtr(char c)
{
    return c == '+' || c == '-' || is_m_or_d_oprtr(c) || is_exp_oprtr(c) || is_paren(c);
}

void find_left_oprtr(int oprtr_pos)
{
    for (int i = oprtr_pos--; !is_oprtr(input[i]); i--) {
        ;;
    }
    l_oprtr_pos = oprtr_pos;
}

void find_right_oprtr(int oprtr_pos)
{
    for (int i = oprtr_pos++; !is_oprtr(input[i]); i++) {
        ;;
    }
    r_oprtr_pos = oprtr_pos;
}

void insert_parens(int *p, int l, int r)
{
    for (int i = len; i > l; i--) {
        input[i] = input[i - 1];
    }
    len++;
    input[l] = '(';
    r++;
    for (int i = len; i > r; i --) {
        input[i] = input[i - 1];
    }
    len++;
    input[r] = ')';
    (*p)++;
}

void handle_oprtr(int *oprtr_pos)
{
    l_oprtr_pos = r_oprtr_pos = 0;
    find_left_oprtr(*oprtr_pos);
    find_right_oprtr(*oprtr_pos);
    if (is_paren(input[l_oprtr_pos]) || is_paren(input[r_oprtr_pos])) {
        ;;
    } else {
        insert_parens(oprtr_pos, l_oprtr_pos, r_oprtr_pos + 1);
    }
}

int main(void)
{
    printf("Start: %s\n", input);
    len = strlen(input);
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_exp_oprtr(input[i])) {
            handle_oprtr(&i);
        }
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_m_or_d_oprtr(input[i])) {
            handle_oprtr(&i);
        }
    }
    printf("End:   %s\n", input);
    return 0;
}
