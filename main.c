#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

struct equation eq;

char input[MAXLEN] = "((1+2)^(5+6+7))/8";
// char input[100] = "1*2+3*4+4*5^6*7+8";
// char input[MAXLEN] = "(((1*2)+3)-4)";

int l_bound;
int r_bound;
bool parens;

int main(void)
{
    add_parens();
    while (verify_oprtr() && verify_parens()) {
    // for (int i = 0; i < 6; i++) {
        l_bound = r_bound = -1;
        printf(
            "\n---------------------------------------\nLoop starting input:\n%s\n---------------------------------------\n",
            input
        );
        parens_exist();
        find_bounds();
        parse();
        convert_str_to_d();
        calculate();
        convert_d_to_str();
        replace_str();

    }
    printf("\nSolved input:\n%s\n", input);
    return 0;
}
