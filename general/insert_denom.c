#include <string.h>

static void insert(char *s)
{
    int len = strlen(s);
    s[len] = '1';
    s[len + 1] = '\0'; 
}
void insert_denom(char *d1, char *d2)
{
    if (*d1 != '\0' && *d2 == '\0') {
        insert(d2);
    } else if (*d2 != '\0' && *d1 == '\0') {
        insert(d1);
    }
}
