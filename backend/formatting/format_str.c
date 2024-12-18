#include <stdlib.h>
#include <string.h>
#include "formatting.h"
#include "../utils/utils.h"

void format_str(char* s)
{
    while (insert_parens(s)
           | remove_unneeded_parens(s)
           | convert_neg_signs(s)
           | remove_1_oprtns(s)
           | move_frctn_neg_signs(s)) {
        if (get_paren_depth(s, NULL)) {
            fprintf(stderr,
                    "\n%s\nError | Imbalanced parentheses:\n%s\n",
                    __FILE__, s);
            exit(1);
        }
    }
}
