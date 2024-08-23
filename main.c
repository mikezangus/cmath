#include <stdio.h>
#include "main.h"


char input[100] = "1+2*3^4-5";

struct Equation eq;
struct Parens parens;
struct Bounds bounds;
struct Switches sw;

static void init(void)
{
    parens.l = parens.r = -1;
    bounds.l = bounds.r = -1;
    sw.parens_exist = 0;
}

int main(void)
{
    add_parens();
    while (check_oprtr_exists(input)) {
        printf("\nStarting equation: %s\n", input);
        init();
        if ((sw.parens_exist = check_parens_exist(input))) {
            find_nearest_parens(input);
        }
        find_bounds();
        parse();
        convert_str_to_d();
        calculate();
        convert_d_to_str();
        insert_result(input);
    }
    printf("\nSolved equation: %s\n", input);
}
