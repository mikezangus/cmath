#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

char input[MAXLEN] = "(1*2)+(3*45)";
int l_parens[MAXLEN];
int r_parens[MAXLEN];
int l_parens_i = 0;
int r_parens_i = 0;

int l_bound;
int r_bound;


bool verify_parens()
{
    int d = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            d++;
        } else if (input[i] == ')') {
            d--;
        } 
    }
    return d == 0;
}


void find_parens(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            l_parens[l_parens_i++] = i;
        } else if (input[i] == ')') {
            r_parens[r_parens_i++] = i;
        }
    }
}

void find_bounds(void)
{
    l_bound = r_bound = 0;
    int min = MAXLEN;
    int d;
    for (int l_i = 0; l_i < l_parens_i; l_i++) {
        printf("\nLEFT LOOP #%d - %d\n", l_i, l_parens[l_i]);
        for (int r_i = 0; r_i < r_parens_i; r_i++) {
            printf("RIGHT LOOP #%d - %d\n", r_i, r_parens[r_i]);
            if (r_parens[r_i] > l_parens[l_i]) {
                d = abs(l_parens[l_i] - r_parens[r_i]);
                printf("Temp: %d | Current min: %d\n", d, min);
                if (d < min) {
                    min = d;
                    l_bound = l_parens[l_i] + 1;
                    r_bound = r_parens[r_i] - 1;
                    printf("New min: %d\n", min);
                    printf("Left: %d | Right: %d\n", l_bound, r_bound);
                }
            } else {
                printf("Invalid, right before left\n");
            }
        }
    }
}

bool is_exp(int a, int b)
{
    for (int i = a; i <= b; i++) {
        return input[i] == '^';
    }
}
bool is_m_or_d(int a, int b)
{
    for (int i = a; i <= b; i++) {
        return input[i] == '*' || input[i] == '/';
    }
}

void chain(int a, int b)
{

}

int main(void)
{
    if (!verify_parens()) {
        printf("Error | Unbalanced parentheses: %s\n", input);
        return 0;
    }
    find_parens();
    printf("Parentheses found:\n");
    for (int i = 0; i < l_parens_i; i++) {
        printf("L: [%d] %d\n", i, l_parens[i]);
    }
    for (int i = 0; i < r_parens_i; i++) {
        printf("R: [%d] %d\n", i, r_parens[i]);
    }
    find_bounds();

    return 0;
}