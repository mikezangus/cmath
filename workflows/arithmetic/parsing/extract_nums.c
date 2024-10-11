#include <ctype.h>

char* extract_num_forwards(char* dst, char* entry)
{
    char* p;
    for (p = entry; *p && (isdigit(*p) || *p == '-'); p++) {
        *dst++ = *p;
    }
    *dst = '\0';
    return p;
}

char* extract_num_backwards(char* dst, char* entry, char* s)
{
    char* p;
    for (p = entry; p >= s && (isdigit(*p) || *p == '-'); p--) {
        ;;
    }
    p = p == s && isdigit(*p) ? p : p + 1;
    for (char* q = p; q <= entry; q++) {
        *dst++ = *q;
    }
    *dst = '\0';
    return p;
}
