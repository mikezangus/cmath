#include <string.h>

void extract_bounded_str(char* dst, const char* start, const char* end)
{
    if (!dst || !start || !end || start > end) {
        return;
    }
    size_t len = end - start + 1;
    strncpy(dst, start, len);
    dst[len] = '\0';
}
