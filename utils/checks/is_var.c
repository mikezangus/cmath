#include <stdbool.h>
#include <string.h>

static const char vars[] = {
    'a', 'b', 'c', 'd', 'f',
    'g', 'm', 'n', 'p', 'q',
    'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z'
};

bool is_var(char c)
{
    return strchr(vars, c);
}

