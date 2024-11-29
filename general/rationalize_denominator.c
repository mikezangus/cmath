#include <stdio.h>
#include <string.h>
#include "../main.h"
#include "../utils/utils.h"
#include "../formatting/formatting.h"

static void find_irrational_denominator(char** l_bound, char** r_bound,
                                        char** insert1, char** insert2,
                                        char** start)
{
    printf("\nFinding irrational denominator: %s\n", *start);
    *l_bound = *r_bound = NULL;

    /* 1. Does div sign exist? */
    char* div_sign = find_char('/', *start, NULL);
    if (!div_sign) {
        printf("1\n");
        *start = *start + strlen(*start) + 1;
        return;
    }
    /* 2. Is the div sign followed by a left paren? */
    printf("Testing: %s\n", div_sign);
    if (*(div_sign + 1) != '(') {
        printf("2\n");
        *start = div_sign + 1;
        return;
    }
    /* 3. Is the character immediately after the number after the div sign ^? */
    char* base_end = extract_num_fwd((char[]){0}, div_sign + 2) + 1;
    printf("Base end: %s\n", base_end);
    if ((base_end == div_sign + 2) || (*(base_end) != '^')) {
        printf("3\n");
        *start = base_end + 1;
        return;
    }
    if (*(base_end + 1) != '(') {
        printf("4\n");
        *start = base_end + 2;
        return;
    }
    char* expn_end = extract_num_fwd((char[]){0}, base_end + 3);
    if ((expn_end == base_end + 3) || (*(expn_end + 1) != '/')) {
        printf("5\n");
        *start = expn_end + 1;
        return;
    }
    char* expd_end = extract_num_fwd((char[]){0}, expn_end + 2);
    printf("expn end + 2: %s\n", expn_end + 2);
    if ((expd_end == (expn_end + 1)) || *(expd_end + 1) != ')') {
        printf("6\n");
        *start = expd_end + 1;
        return;
    }
    *l_bound = div_sign + 2;
    *r_bound = expd_end + 1;
    *insert1 = div_sign - 1;
    *insert2 = *r_bound + 1;
    *start = *r_bound + 1;
}

void rationalize_denominator(char* src)
{
    format_str(src);
    char* p = src;
    char* l_bound, * r_bound, * insert1, * insert2;
    while (*p) {
        printf("\nRationalize denominator loop: %s\n", p);
        l_bound = r_bound = insert1 = insert2 = NULL;
        find_irrational_denominator(&l_bound, &r_bound, &insert1, &insert2, &p);
        if (!l_bound || !r_bound || !insert1 || !insert2) {
            continue;
        } else {
            break;
        }
    }

    char buff[STR_MAXLEN] = {0};
    strcpy(buff, "*(");
    extract_bounded_str(buff + 2, l_bound, r_bound);
    strcpy(buff + strlen(buff), ")\0");
    printf("Extracted: %s\n", buff);
    insert_str(src, buff, insert1);
    insert_str(src, buff, insert2 + strlen(buff));
    printf("Inserted:  %s\n", src);
}
