#include <string.h>
#include "../main.h"

static void insert(char *s)
{
    int len = strlen(s);
    s[len ] = '1';
    s[len + 1] = '\0'; 
}
void insert_denom(void)
{
    if (*(eq.op1ds) != '\0' && *(eq.op2ds) == '\0') {
        insert(eq.op2ds);
    } else if (*(eq.op2ds) != '\0' && *(eq.op1ds) == '\0') {
        insert(eq.op1ds);
    }
}
