#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char input[100] = "1+2^2-(1+1)*1";
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

void find_left_oprtr(int pos)
{
    for (int i = pos--; !is_oprtr(input[i]); i--) {
        ;;
    }
    l_oprtr_pos = pos;
}

void find_right_oprtr(int pos)
{
    for (int i = pos++; !is_oprtr(input[i]); i++) {
        ;;
    }
    r_oprtr_pos = pos + 1;
}

void insert_parens(int l, int r)
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
}

void handle_oprtr(int *pos)
{
    l_oprtr_pos = r_oprtr_pos = 0;
    find_left_oprtr(*pos);
    find_right_oprtr(*pos);
    if (is_paren(input[l_oprtr_pos]) || is_paren(input[r_oprtr_pos])) {
        ;;
    } else {
        insert_parens(l_oprtr_pos, r_oprtr_pos);
        (*pos)++;
    }
}

int main(void)
{
    len = strlen(input);
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_exp_oprtr(input[i]) || is_m_or_d_oprtr(input[i])) {
            handle_oprtr(&i);
        }
    }
    return 0;
}
