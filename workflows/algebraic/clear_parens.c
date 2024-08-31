// #include "../../utils/utils.h"
// #include <stdio.h>

// static int find_i_eqsign(char *s)
// {
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '=') {
//             return i;
//         }
//     }
//     return -1;
// }

// void clear_parens(char *s)
// {
//     int i_eqsign = find_i_eqsign(s);
//     if (s[0] == '(' && s[i_eqsign - 1] == ')') {
//         printf("Conditions to clear parens met\n");
//         collapse_str(s, 0, 0);
//         collapse_str(s, i_eqsign - 2, i_eqsign - 2);
//     }
// }
