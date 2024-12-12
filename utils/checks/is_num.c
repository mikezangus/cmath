#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool is_num(const char* p, const char* src)
{   
    return isdigit(*p)
           || (*p == '.' && src && p > src && isdigit(*(p - 1)))
           || (*p == '-' && src && p == src)
           || (*p == '-' && src && p > src && *(p - 1) == '=');
}
