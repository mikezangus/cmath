#include "../formatting.h"

void format_parens(char* s)
{
    remove_parens(s);
    insert_div_parens(s);
}
