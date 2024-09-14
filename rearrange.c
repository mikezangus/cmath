#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "workflows/algebraic/algebraic.h"
#include "general/general.h"
#include "utils/utils.h"

static void find(char *s)
{
    int depth = 0;
    char* left1 = NULL;
    char* right1 = NULL;

    char* left2 = NULL;
    char* right2 = NULL;
    
    bool prev_l = false;

    bool set_found = false;


    int i = 0;
    for (char *p = s; *p; p++, i++) {
        printf(
            "\n\n[%d] Loop start - L: %c%c | R: %c%c \n",
            i,
            left1 ? *left1 : '`',
            left1 ? *(left1 + 1) : '`',
            right1 ? *(right1 - 1) : '`',
            right1 ? *right1 : '`'
        );
        if (!set_found) {
            if (*p == '(') {
                if (prev_l) {
                    depth++;
                } else {
                    left1 = p;
                    prev_l = true;
                }
            } else if (*p == ')') {
                right1 = p;
                set_found = true;
                prev_l = false;
            }
        } else {
            if (*p == '(') {
                if (prev_l) {
                    printf("Different depths. Exit\n");
                    break;
                } else {
                    left2 = p - 1;
                    prev_l = true;
                }
            } else if (*p == ')') {
                right2 = p;
            }
        }
        printf(
            "[%d] Loop end   - L: %c%c | R: %c%c \n",
            i,
            left1 ? *left1 : '`',
            left1 ? *(left1 + 1) : '`',
            right1 ? *(right1 - 1) : '`',
            right1 ? *right1 : '`'
        );
    }

    if (!left1 || !right1 || !left2 || !right2) {
        printf("There are not multiple sets. Exiting\n");
        return;
    }


    print_bounded_str(left1, right1);
    print_bounded_str(left2, right2);


    char buff[STR_MAXLEN] = {0};
    char* ptr_buff = buff;
    for (char* p = right1 + 1; p < left2 && *p; p++, ptr_buff++) {
        *ptr_buff = *p;
    }
    printf("Buffer populated: %s\n", buff);

    collapse_str(right1 + 2, left2);
    printf("Collapsed: %s\n", s);

    insert_str(s, buff, right2 - strlen(buff) + 1);
    printf("Re-arranged str: %s\n", s);


}

int main(void)
{
    char s[STR_MAXLEN] = "5 + (2x^2) + 6 + 3x^3";
    printf("\nStarting input: %s\n", s);
    clean_input(s);
    insert_eqzero(s);
    insert_1(s);
    insert_parens(s);
    printf("\nFormatted:\n    ");
    print_str_indexes(s, s);
    find(s);
}
