#include <string.h>

void insert_eqzero(char* s)
{
    if (!strchr(s, '=')) {
        strcat(s, "=0");
    }
}
