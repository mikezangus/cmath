#include <ctype.h>
#include "../../main.h"
#include "../../utils/utils.h"

void move_external_neg_sign(char* s, Bounds* b)
{
    if (b->l - 2 < s) {
        return;
    }
    char* div_oprtr = find_char('/', b->l + 1, b->r - 1);
    if (!div_oprtr) {
        return;
    }
    char* sub_oprtr = b->l - 2;
    if (*sub_oprtr != '-'
        || *(sub_oprtr + 1) != '('
        || sub_oprtr + 1 != b->l - 1
        || sub_oprtr > s && isdigit(*(sub_oprtr - 1))) {
        return;
    }
    b->l--;
    collapse_str(sub_oprtr, sub_oprtr);
    insert_str(s, "-", b->l);
}
