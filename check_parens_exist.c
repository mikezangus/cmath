int check_parens_exist(char *s)
{
    int l = 0;
    for (char *p = s; *p != '\0'; p++) {
        if (*p == '(') {
            l = 1;
        }
        if (*p == ')' && l) {
            return 1;
        }
    }
    return 0;
}
