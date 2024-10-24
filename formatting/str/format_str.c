#include "../formatting.h"

void format_str(char* s)
{
    remove_unneeded_parens(s);
    convert_neg_signs(s);
    insert_parens(s);
}
