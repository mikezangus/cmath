#include <ctype.h>
#include <stdio.h>
#include "header.h"

void convert(int term_idx)
{
    printf("\nCONVERT\n");
    eq.n1d = 0.0;
    eq.n2d = 0.0;
    if (!term_idx) {
        for (int i = 0; eq.n1c[i] != '\0'; i++) {
            eq.n1d = eq.n1d * 10 + (eq.n1c[i] - '0');
        } 
    } else {
        eq.n1d = eq.result;
    }
    for (int i = 0; eq.n2c[i] != '\0'; i++) {
        eq.n2d = eq.n2d * 10 + (eq.n2c[i] - '0');
    }
    printf("n1d: %f\n", eq.n1d);
    printf("n2d: %f\n", eq.n2d);






    // printf("Starting multi-term: %d\n", eq.multi_term);
    // printf("Starting result: %f\n", eq.result);
    // if (eq.multi_term > 1) {
    //     printf("Multi-term\n");
    //     eq.n1d = eq.result;
    // } else {
    //     eq.n1d = 0.0;
    //     for (int i = 0; i < eq.n1c_cnt; i++) {
    //         eq.n1d = eq.n1d * 10 + (eq.n1c[i] - '0');
    //     }
    // }
    // eq.n2d = 0.0;
    // for (int i = 0; i < eq.n2c_cnt; i++)
    //     eq.n2d = eq.n2d * 10 + (eq.n2c[i] - '0');
    // printf("n1d: %f\n", eq.n1d);
    // printf("n2d: %f\n", eq.n2d);
}
