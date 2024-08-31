// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include "../../main.h"
// #include "../../utils/utils.h"

// int is_outside_parens(int pos)
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
//     return (l_scale == 0 && r_scale == 0);
// }

// int find_r_bound(int pos)
// {
//     int i;
//     for (i = pos + 1; isdigit(input[i]); i++) {
//         ;;
//     }
//     return i - 1;
// }

// void find_bounds_alg(int i, int *l_bound, int *r_bound)
// {
//     if (is_prec3_oprtr(input[i])) {
//         *l_bound = i;
//         *r_bound = find_r_bound(i);
//         print_str("", input);
//         printf("Bounds - L: %d | R: %d\n", *l_bound, *r_bound);
//     }
// }