#include <stdio.h>
#include "header.h"

char input[MAXLEN];
struct equation eq;

int main(void)
{
    get_input();
    parse();
    convert();
    calculate();
    return 0;
}
