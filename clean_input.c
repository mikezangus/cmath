#include "main.h"

void clean_input(void)
{
    char *p1 = input;
    char *p2 = input;
    while (*p1 != '\0') {
        if (*p1 != ' ') {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    *p2 = '\0';
}
