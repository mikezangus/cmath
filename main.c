#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

struct equation eq;

// char input[MAXLEN] = "((1+2)^(5+6+7))/8";
// char input[MAXLEN] = "1*2+3*4+4*5^6*7+8";
// char input[MAXLEN] = "(((1*2)+3)-4)";

char input[MAXLEN] = "1x=2";

int l_bound;
int r_bound;
bool parens_exist;
bool var_exists;
int i_var;

int main(void)
{
    var_exists = false;
    i_var = -1;
    add_parens();
    find_var();
    if (i_var >= 0) {
        add_mult();
    }


    while (verify_oprtr() && verify_parens()) {
    // for (int i = 0; i < 6; i++) {
        l_bound = r_bound = -1;
        printf(
            "\n\n---------------------------------------\nLoop starting input:\n%s\n---------------------------------------\n",
            input
        );
        if (handle_x1()) {
            continue;
        }
        find_parens();
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
