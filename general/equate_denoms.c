void equate_denoms(double *p_n1, double *p_d1, double *p_n2, double *p_d2)
{
    double n1 = *p_n1;
    double d1 = *p_d1;
    double n2 = *p_n2;
    double d2 = *p_d2;
    if (d1 != d2) {
        *p_n1 = n1 * d2;
        *p_n2 = n2 * d1;
        *p_d1 = *p_d2 = d1 * d2;
    }
}
