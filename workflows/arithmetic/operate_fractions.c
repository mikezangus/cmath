
#include <stdio.h>

double op1n = 1.0;
double op1d = 4.0;
double op2n = 1.0;
double op2d = 64.0;

double op1n_scaled = 0.0;
double op1d_scaled = 0.0;
double op2n_scaled = 0.0;
double op2d_scaled = 0.0;

double opn = 0.0;
double opd = 0.0;

void get_common_denoms(double a_n, double a_d, double b_n, double b_d)
{
    if (a_d != b_d) {
        op1n_scaled = a_n * b_d;
        op1d_scaled = a_d * b_d;
        op2n_scaled = b_n * a_d;
        op2d_scaled = b_d * a_d;
    }
}

void operate_numerators(char oprtr, double a_n, double a_d, double b_n, double b_d)
{
    if (a_d != b_d) {
        return;
    } else {
        opd = a_d;
    }
    switch (oprtr) {
    case '+':
        opn = a_n + b_n;
        break;
    case '-':
        opn = a_n - b_n;
        break;
    }
}

int get_gcd(int a, int b)
{
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduce_fraction(double *n, double *d, double gcd)
{
    (*n) /= gcd;
    (*d) /= gcd;
}

void operate_fractions(void)
{
    char oprtr = '+';
    printf("%f/%f %c %f/%f\n", op1n, op1d, oprtr, op2n, op2d);

    get_common_denoms(op1n, op1d, op2n, op2d);
    printf("%f/%f %c %f/%f\n", op1n_scaled, op1d_scaled, oprtr, op2n_scaled, op2d_scaled);

    operate_numerators(oprtr, op1n_scaled, op1d_scaled, op2n_scaled, op2d_scaled);
    printf("\n%f/%f %c %f/%f\n= %f/%f\n", op1n_scaled, op1d_scaled, oprtr, op2n_scaled, op2d_scaled, opn, opd);

    int gcd = get_gcd(opn, opd);
    printf("GCD: %d\n", gcd);

    reduce_fraction(&opn, &opd, gcd);
    printf("Reduced: %f/%f\n", opn, opd);
}
