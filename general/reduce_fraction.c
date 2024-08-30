long long int get_gcd(long long int a, long long int b)
{
    long long int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void reduce_fraction(double *n, double *d)
{
    long long int gcd = get_gcd(*n, *d);
    (*n) /= gcd;
    (*d) /= gcd;
}
