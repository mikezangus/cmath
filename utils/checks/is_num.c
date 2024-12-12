#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool is_num(const char* p, const char* min)
{   
    return isdigit(*p)
           || (*p == '.' && min && p > min && isdigit(*(p - 1)))
           || (*p == '-' && min && p > min && !isdigit(*(p - 1)))
           || (*p == '-' && min && p == min);
}
