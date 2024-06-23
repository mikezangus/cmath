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
        printf("\n----------------------------------------\nTerm %d\n", i + 1);
        parse(i);
        convert(i);
        if (!calculate()) {
            return 0;
        }
    }
    printf("\n\nResult: %f\n", eq.result);
    return 0;
}
