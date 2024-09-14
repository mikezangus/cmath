#include <string.h>

int var_exists(char* s)
{
    return strchr(s, 'x') != NULL;
}
