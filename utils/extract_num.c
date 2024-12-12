#include "utils.h"

char* extract_num(char* dst, const char* start, const char* src, int direction)
{
    const char* l = direction > 0 ? start : walk_num_bwd(start, src);
    const char* r = l;
    while (*r && is_num(r, start)) {
        *dst++ = *r++;
    }
    *dst = '\0';
    return (char*)(direction > 0 ? r - 1 : l);
}
