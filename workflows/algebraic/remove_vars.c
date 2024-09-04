#include <ctype.h>

void remove_vars(char *s)
{
    char *in = s;
    char *out = s;
    while (*in != '^') {
        if (isdigit(*in)) {
            *out = *in;
            out++;
        }
        in++;
    }
    *out = '\0';
}
