#include "../../main.h"
#include "../../general/general.h"
#include "../../utils/utils.h"
#include "arithmetic.h"
#include <ctype.h>
#include "stdio.h"
#include <string.h>

// int i_first_digit;
// int i_last_digit;

// static void init(void)
// {
//     i_first_digit = i_last_digit = -1;
// }

// static int find_first_digit(int start)
// {
//     for (int i = start; !is_oprtr(input[i]) && input[i] != '\0'; i++) {
//         if (isdigit(input[i])) {
//             return i;
//         }
//     }
//     return -1;
// }

// static int find_last_digit(int start)
// {
//     int i;
//     for (i = start; !is_oprtr(input[i]) && input[i] != '\0'; i++) {
//         ;;
//     }
//     return i - 1;
// }



// static void process(void)
// {
//     init();
//     for (int i = 0; input[i] != '\0'; i++) {
//         if (is_oprtr(input[i])) {
//             init();
//             continue;
//         }
//         if (i_first_digit < 0) {
//             i_first_digit = find_first_digit(i);
//         }
//         if (i_last_digit < 0 && i_first_digit > -1) {
//             i_last_digit = find_last_digit(i_first_digit);
//         }
//         if (input[i_first_digit - 1] != '/' && input[i_last_digit + 1] != '/') {
//             insert_denom(&i, i_last_digit + 1);
//             continue;
//         }
//     }
// }

// void insert_denoms(void)
// {
//     for (char *p = input; *p != '\0'; p++) {
//         if (*p == '/' && isdigit(*(p + 1)) && isdigit(*(p - 1))) {
//             process();
//             break;
//         }
//     }
// }









int i_digit_start;
int i_digit_end;

static void init(void)
{
    i_digit_start = i_digit_end = -1;
}

static void insert_denom(int i_insertion, int *i)
{
    printf("Before insertion: %s\n", input);
    expand_str(input, "/1", i_insertion);
    insert_str(input, "/1", i_insertion);
    (*i) = (i_insertion + 2);
    init();
    printf("After insertion: %s\n", input);

}

int find_start_of_paren_group(int start)
{
    int i;
    for (i = start; input[i] != '\0' && input[i] != '('; i++) {
        ;;
    }
    return i;
}

int find_i_via_scale(int start)
{
    int scale = 0;
    for (int i = start; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            scale++;
        } else if (input[i] == ')') {
            scale--;
        }
        if (scale == 0) {
            return i;
        }
    }
    return -1;
}

int find_end_of_paren_group(int start)
{
    return (find_i_via_scale(start));
}

void handle_parens(void)
{
    int start;
    int end;
    print_str("", input);
    for (int i = 0; i < 10; i++) {
        start = find_start_of_paren_group(i);
        printf("Start found at input[%d] = %c\n", start, input[start]);
        if (!(end = find_end_of_paren_group(start))) {
            return;
        }
        printf("End found at input[%d] = %c\n", end, input[end]);
        if (is_oprtr(input[end + 1])) {
            insert_denom(end + 1, &i);
        }
        i = end + 1;
    }
}

int find_digit_start(int start)
{
    for (int i = start; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            return i;
        }
    }
    return -1;
}

int find_digit_end(int start)
{
    int end = strlen(input) - 1;
    int i;
    for (i = start; isdigit(input[i]) && i <= end; i++) {
        ;;
    }
    return i;
}

void handle_general(void)
{
    for (int i = 0; input[i] != '\0'; i++) {
        printf("[%d] %c\n", i, input[i]);
        if (input[i] == '(') {
            i = find_i_via_scale(i) + 3;
        }
        if (input[i] == '/') {
            continue;
        }
        if (is_oprtr(input[i]) && input[i + 1] != '(') {
            i_digit_start = find_digit_start(i + 1);
            i_digit_end = find_digit_end(i_digit_start);
            insert_denom(i_digit_end, &i);
        }
    }
}

void insert_denoms(void)
{
    handle_parens();
    handle_general();
}