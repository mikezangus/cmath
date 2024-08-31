// #include "../../utils/utils.h"

// static int is_clearable_zero(char *s, int *start, int *end)
// {
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '0') {
//             if (s[i - 1] == '+') {
//                 *start = i - 1;
//                 *end = i;
//                 return 1;
//             } else if (s[i + 1] == '+') {
//                 *start = i;
//                 *end = i + 1;
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// void clear_add_zero(char *s)
// {
//     int start = -1;
//     int end = -1;
//     if (is_clearable_zero(s, &start, &end)) {
//         collapse_str(s, start, end);
//     }
// }
