void create_var_str(char *in_var, char *in_exp, char *out)
{
    char *p_out = out;
    for (char *p = in_var; *p != '\0'; p++) {
        *p_out = *p;
        p_out++;
    }
    *p_out = '^';
    p_out++;
    for (char *p = in_exp; *p != '\0'; p++) {
        *p_out = *p;
        p_out++;
    }
    *p_out = '\0';
}
