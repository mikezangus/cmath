int check_eqsign(char *s)
{
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '=') {
            return 1;
        }
    }
    return 0;
}
