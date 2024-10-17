#include <string.h>
#include "../../main.h"

void flip_frctn_divisor(char* oprtr, char* num, char* den)
{
    if (*oprtr != '/' || !*num || !*den) {
        return;
    }
    char buff[STR_MAXLEN] = {0};
    strcpy(buff, den);
    strcpy(den, num);
    strcpy(num, buff);
    *oprtr = '*';
}
