// #include "../../main.h"
// #include "../../utils/utils.h"
// #include "../../general/general.h"
// #include "algebraic.h"
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// int l_bound;
// int r_bound;

// struct Eq_Alg eq_alg;

// static void init(void)
// {
//     l_bound = r_bound = 0;
// }

// static char invert_oprtr(char c)
// {
//     switch (c) {
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

// static void parse_balance(int l_bound, int r_bound)
// {
//     printf("Parsing:\n");
//     int j = 0;
//     memset(eq_alg.balance, '\0', 100);
//     for (int i = l_bound; i <= r_bound; i++) {
//         printf("[%d] %c\n", i, input[i]);
//     }
//     for (int i = l_bound; i <= r_bound; i++) {
//         if (is_oprtr(input[i])) {
//             eq_alg.balance[j++] = invert_oprtr(input[i]);
//         } else if (isdigit(input[i])) {
//             eq_alg.balance[j++] = input[i];
//         }
//     }
//     printf("Parsed: %s\n", eq_alg.balance);
// }

// static void insert_balance(int i)
// {
//     insert_str(input, eq_alg.balance, i);
// }

// static int find_eqsign(char *s)
// {
//     for (int i = 0; input[i] != '\0'; i++) {
//         if (input[i] == '=') {
//             return i;
//         }
//     }
//     return -1;
// }

// static int has_var(char *s, int l_bound, int r_bound) {
//     for (int i = l_bound; i <= r_bound && s[i] != '\0'; i++) {
//         if (input[i] == 'x') {
//             return 1;
//         }
//     }
//     return 0;
// }

// int process_algebraic(void)
// {
//     // printf("\nStart: %s\n\n", input);
//     // if (!check_eqsign_exists(input)) {
//     //     insert_eqsign(input);
//     // }
//     // insert_mult(input);
//     // add_parens();
//     // // while (check_oprtr_exists()) {
//     // for (int i = 0; i < 3; i++) {
//     //     printf("\n\n------------------------------\nNEW LOOP\n------------------------------\n");
//     //     find_bounds_balance(&l_bound, &r_bound);
//     //     printf("Bounds - L: %d | R: %d\n", l_bound, r_bound);
//     //     if (has_var(input, l_bound, r_bound)) {
//     //         printf("HAS VAR\n");
//     //     }
//     //     parse_balance(l_bound, r_bound);
//     //     insert_balance(r_bound + 1);
//     //     insert_balance(strlen(input));
//     //     printf("Inserted: %s\n", input);

//     //     r_bound += strlen(eq_alg.balance);
//     //     printf("\n\n\nSEQUENCE 1/2\n\n");
//     //     sequence(l_bound, r_bound);
//     //     printf("\n\nSEQUENCE 2/2\n\n");
//     //     sequence(find_eqsign(input) + 1, strlen(input));

//     // }
//     return 1;

// }