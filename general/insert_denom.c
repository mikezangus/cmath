#include <string.h>

static void create_denom(char* s)
{
    int len = strlen(s);
    s[len] = '1';
    s[len + 1] = '\0'; 
}

void insert_denom(char* d1, char* d2)
{
    if (*d1 && *d2 == '\0') {
        create_denom(d2);
    } else if (*d2 && *d1 == '\0') {
        create_denom(d1);
    }
}
