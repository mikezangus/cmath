#include <stdio.h>
#include "header.h"

char input[MAXLEN];
char terms[MAXLEN][MAXLEN];
struct equation eq;

int main(void)
{
    get_input();
    create_terms();
    static int i;
    for (i = 0; terms[i][0] != '\0'; i++) {
        parse(i);
        convert(i);
        if (!calculate()) {
            return 0;
        }
    }
    printf("\n\nResult: %f\n", eq.result);
    return 0;
}
