void clean_input(char* s)
{
    char* p1 = s;
    char* p2 = s;
    while (*p1 != '\0') {
        if (*p1 != ' ') {
            *p2 = *p1;
            p2++;
        }
        p1++;
    }
    *p2 = '\0';
}
