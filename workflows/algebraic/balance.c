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
//     int j = 0;
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
