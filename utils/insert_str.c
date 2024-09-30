#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool is_pos_inside_dst(char* dst_str, size_t dst_len, const char* insert_pos)
{
    return (insert_pos >= dst_str) && (insert_pos <= dst_str + dst_len);
}

static void expand(char* dst_str, size_t dst_len, const char* insert_pos, size_t insert_len)
{
    const char* src = dst_str + dst_len;
    char* dst = dst_str + dst_len + insert_len;
    while (src >= insert_pos) {
        *dst-- = *src--;
    }
}

static void insert(const char* src_str, const char* insert_pos)
{
    char* dst = (char*)insert_pos;
    while (*src_str) {
        *dst++ = *src_str++;
    }
}

void insert_str(char* dst_str, const char* src_str, const char* insert_pos)
{
    size_t dst_len = strlen(dst_str);
    if (!is_pos_inside_dst(dst_str, dst_len, insert_pos)) {
        fprintf(
            stderr,
            "\n%s | Error: insert_pos not inside of dst_str\n  dst_str: %p - %p\n  insert_pos: %p\n",
            __FILE__, dst_str, dst_str + dst_len, insert_pos);
        return;
    }
    expand(dst_str, dst_len, insert_pos, strlen(src_str));
    insert(src_str, insert_pos);
}
