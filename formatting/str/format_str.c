#include <stdlib.h>
#include <string.h>
#include "../formatting.h"
#include "../../utils/utils.h"

static void sequence(char* start)
{
    remove_unneeded_parens(start);
    convert_neg_signs(start);
    insert_parens(start);
}

void format_str(char* s)
{
    sequence(s);
    char* eq_sign = strchr(s, '=');
    if (eq_sign) {
        sequence(eq_sign + 1);
    }
    if (get_paren_depth(s, NULL) != 0) {
        fprintf(stderr,
                "\n%s\nError | Imbalanced parentheses:\n  %s\nExiting.\n",
                __FILE__, s);
        exit(1);
    }
}
