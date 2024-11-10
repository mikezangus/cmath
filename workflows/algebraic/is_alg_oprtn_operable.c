#include <stdbool.h>
#include <string.h>

static bool is_prec2_operable(char v1, char v2)
{
    return v1 == v2;
}

static bool is_prec3_operable(char v1, const char* e1, char v2, const char* e2)
{
    if (v1 != v2) {
        return false;
    }
    return strcmp(e1, e2) == 0;
}

bool is_alg_oprtn_operable(char v1, const char* e1,
                           char oprtr,
                           char v2, const char* e2)
{
    switch (oprtr) {
        case '*':
        case '/': return is_prec2_operable(v1, v2);
        case '+':
        case '-': return is_prec3_operable(v1, e1, v2, e2);
        default: return false;
    }
}
