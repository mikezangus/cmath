#include <stdio.h>
#include "header.h"

char input[MAXLEN];
char terms[MAXLEN][MAXLEN];
struct equation eq;

int main(void)
{
    get_input();
    create_terms();
    for (int i = 0; terms[i][0] != '\0'; i++) {
        printf("\n\n--------------------\nLOOP [%d]\n--------------------\n", i);
        parse(i);
        convert(i);
        calculate();
    }
    return 0;
}
