#include <string.h>
#include "formatting.h"

void move_fract_neg_sign(char* s)
{
    if (!strchr(s, '/')) {
        return;
    }
    char* neg_sign = strchr(s, '-');
    if (!neg_sign) {
        return;
    }
    collapse_str(neg_sign, neg_sign);
    insert_str(s, "-(", s);
    insert_str(s, ")", s + strlen(s));
}
