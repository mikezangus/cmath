#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool is_num(const char* p, const char* start)
{   
    return isdigit(*p)
           || (start ? (*p == '-' && p == start) : *p == '-')
           || *p == '.';
}
