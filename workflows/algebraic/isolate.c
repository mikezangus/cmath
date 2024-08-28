// #include "algebraic.h"
// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include "../../utils/utils.h"
// #include "../../main.h"

// char buff[MAXLEN];
// char oprtr;
// char inv_oprtr;
// int i_first_digit;
// int i_last_digit;

// int find_first_l_paren(void)
// {
//     int i;
//     for (i = 0; input[i] != '('; i++) {
//         ;;
//     }
//     return i;
// }

// int find_last_r_paren(void)
// {
//     int i;
//     for (i = i_eqsign; input[i] != ')'; i--) {
//         ;;
//     }
//     return i;
// }

// void parse_operand(int l_paren, int r_paren)
// {
//     printf("Parsing operand: %s\n", input);
//     int i_buff = 0;
//     if (l_paren == 0) {
//         printf("Flow 1\n");
//         for (int i = r_paren + 1; i < i_eqsign; i++) {
//             if (isdigit(input[i])) {
//                 if (i_first_digit < 0) {
//                     i_first_digit = i;
//                 }
//                 i_last_digit = i;
//                 buff[i_buff++] = input[i];
//                 continue;
//             }
//         }
//     } else {
//         printf("Flow 2\n");
//         for (int i = 0; i < l_paren && isdigit(input[i]); i++) {
//             if (i_first_digit < 0) {
//                 i_first_digit = i;
//             }
//             i_last_digit = i;
//             buff[i_buff++] = input[i];
//             continue;
//         }
//     }
// }

// void parse_oprtr(void) {
//     printf("First digit - input[%d] = %c\n", i_first_digit, input[i_first_digit]);
//     if (is_oprtr(input[i_first_digit - 1])) {
//         oprtr = input[i_first_digit - 1];
//         printf("Operator found path 1\n");
//     } else if (is_prec2_oprtr(input[i_last_digit + 1])) {
//         printf("input[%d]: %c is a prec 2 oprtr\n", i_last_digit + 1, input[i_last_digit + 1]);
//         oprtr = input[i_last_digit + 1];
//     }
//     else {
//         printf("Failed to find operator, assuming + before first digit\n");
//         oprtr = '+';
//     }
// }

// char invert_oprtr(char oprtr)
// {
//     switch (oprtr) {
//     case '+':
//         return '-';
//     case '-':
//         return '+';
//     case '*':
//         return '/';
//     case '/':
//         return '*';
//     default:
//         return '\0';
//     }
// }

// void populate_insertion(char *insertion, int insertion_len, char *buff, char inverted_oprtr)
// {
//     printf("Buff via populate_insertion: %s\n", buff);
//     insertion[0] = inverted_oprtr;
//     int j = 0;
//     for (int i = 1; i <= insertion_len; i++) {
//         insertion[i] = buff[j++];
//     }
//     printf("Insertion: %s\n", insertion);
// }

// void isolate(void)
// {
//     memset(buff, '\0', MAXLEN);
//     i_first_digit = i_last_digit = -1;
//     int l_paren = find_first_l_paren();
//     int r_paren = find_last_r_paren();

//     parse_operand(l_paren, r_paren);
//     parse_oprtr();

//     char inverted_oprtr = invert_oprtr(oprtr);
//     int insertion_len = strlen(buff) + 1;
//     char insertion[insertion_len];
//     populate_insertion(insertion, insertion_len, buff, inverted_oprtr);


//     expand_str(input, insertion, i_last_digit + 1);
//     insert_str(input, insertion, i_last_digit + 1);
//     insert_str(input, insertion, strlen(input));

// }
