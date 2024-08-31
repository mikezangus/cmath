// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include "../../main.h"
// #include "../../utils/utils.h"

// static int is_outside_parens(int pos)
// {
//     int l_scale = 0;
//     for (int i = pos; i >= 0; i--) {
//         if (input[i] == '(') {
//             l_scale++;
//         } else if (input[i] == ')') {
//             l_scale--;
//         }
//     }
//     int r_scale = 0;
//     for (int i = pos; input[i] != '\0'; i++) {
//         if (input[i] == '(') {
//             r_scale++;
//         } else if (input[i] == ')') {
//             r_scale--;
//         }
//     }
//     printf("Scales - L: %d | R: %d\n", l_scale, r_scale);
//     return (l_scale == 0 && r_scale == 0);
// }

// static int find_r_bound(int pos)
// {
//     int i;
//     for (i = pos + 1; isdigit(input[i]); i++) {
//         ;;
//     }
//     return i - 1;
// }

// void find_bounds_balance(int *l_bound, int *r_bound)
// {
//     *l_bound = *r_bound = -1;
//     for (int i = 0; input[i] != '\0'; i++) {
//         if (is_prec3_oprtr(input[i])) {
//             printf("[%d] prec3 oprtr\n", i);
//             if (is_outside_parens(i)) {
//                 printf("Not in parens\n");
//                 *l_bound = i;
//                 *r_bound = find_r_bound(i);
//                 return;
//             }
//         }
//     }
//     for (int i = 0; input[i] != '\0'; i++) {
//         if (is_oprtr(input[i])) {
//             printf("[%d] general oprtr\n", i);
//             if (is_outside_parens(i)) {
//                 printf("Not in parens\n");
//                 *l_bound = i;
//                 *r_bound = find_r_bound(i);
//                 return;
//             }
//         }
//     }
// }
