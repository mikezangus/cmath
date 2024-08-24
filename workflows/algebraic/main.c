#include <stdio.h>
#include "algebraic.h"

char input[] = "1+2x*3";



int main(void)
{
    printf("Input: %s\n", input);

    if (!check_eqsign(input)) {
        insert_eqzero(input);
    }
    printf("Input: %s\n", input);
}