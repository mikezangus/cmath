#include <string.h>
#include "../main.h"

void flip_frctn_divisor(char* oprtr, char* n, char* d)
{
    if (*oprtr != '/' || !*n || !*d) {
        return;
    }
    char buff[STR_MAXLEN] = {0};
    strcpy(buff, d);
    strcpy(d, n);
    strcpy(n, buff);
    *oprtr = '*';
}
