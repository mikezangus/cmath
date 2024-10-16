#include "../formatting.h"

void format_parens(char* s)
{
    remove_parens(s);
    add_parens(s);
}
