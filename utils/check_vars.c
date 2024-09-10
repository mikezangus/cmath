#include <stdbool.h>
#include <string.h>

static const char vars[] = {
    'a', 'b', 'c', 'd', 'f',
    'g', 'm', 'n', 'p', 'q',
    'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z'
};

bool char_is_var(char c)
{
    return strchr(vars, c);
}

bool str_contains_var(char* s)
{
    while (*s){
        if (char_is_var(*s)) {
            return true;
        }
        s++;
    }
    return false;
}
