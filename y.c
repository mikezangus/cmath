#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


char input[100] = "1*2+3/5*4+4*4*4";
int len;
int prev_oprtr_pos = 0;
int prev_prec_oprtr_pos = 0;
int parens_open = 0;


bool is_oprtr(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool is_precedent_oprtr(char c)
{
    return c == '*' || c == '/' || c == '^';
}

int insert_space(void)
{
    int pos;
    if (prev_oprtr_pos != prev_prec_oprtr_pos && !parens_open) {
        pos = prev_oprtr_pos + 1;
    } else {
        pos = prev_oprtr_pos;
    }
    for (int i = len; i >= pos; i--) {
        input[i] = input[i - 1];
    }
    input[pos] = '\0';
    len++;
    return pos;
}

void insert_paren(int pos)
{
    input[pos] = parens_open ? ')' : '(';
    parens_open ^= 1;
    printf("Inserted parenthesis: %s\n", input);
}

void handle_paren(void)
{
    int pos = insert_space();
    insert_paren(pos);
}

void handle_oprtr(int *i)
{
    if (parens_open) {
        prev_oprtr_pos = *i;
        handle_paren();
    }
    if (is_precedent_oprtr(input[*i])) {
        handle_paren();
        (*i)++;
        prev_prec_oprtr_pos = *i;
    }
    prev_oprtr_pos = *i;
}

int main(void)
{
    len = strlen(input);
    printf("\nStarting equation: %s\n", input);
    for (int i = 0; i <= len; i++) {
        printf("\nLOOP [%d] %c\n------------------------------\n", i + 1, input[i]);
        printf("Current equation: %s\n", input);
        if (is_oprtr(input[i])) {
            handle_oprtr(&i);
        }
        if (i == len && parens_open) {
            insert_paren(i);
            len++;
        }
    }
    printf("\nEnding equation: %s\n", input);
}
