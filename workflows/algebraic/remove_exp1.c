#include <ctype.h>
#include <string.h>

void remove_exp1(char *s)
{
    char *p_x = strchr(s, 'x');
    if (
        *(p_x + 1) == '^' &&
        *(p_x + 2) == '1' &&
        !isdigit(*(p_x + 3))
    ) {
        *(p_x + 2) = '\0';
        *(p_x + 1) = '\0';
    }
}
