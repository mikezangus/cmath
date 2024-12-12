#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_str(char* dst, char* insert_pos, const char* src)
{
    if (!insert_pos || !*src) {
        fprintf(stderr,
                "\n%s\nError | NULL value(s) pased into insert_str()\n",
                __FILE__);
        exit(1);
    }
    size_t dst_len = strlen(dst);
    if (!(dst <= insert_pos && insert_pos <= dst + dst_len)) {
        fprintf(stderr,
                "\n%s\n"
                "Error | Insert position outside of destination string\n"
                "  insert: %p\n"
                "  dst:    %p - %p\n",
                __FILE__, insert_pos, dst, dst + dst_len);
        exit(1);
    }
    size_t src_len = strlen(src);
    memmove(insert_pos + src_len, insert_pos, dst_len - (insert_pos - dst) + 1);
    memcpy(insert_pos, src, src_len);
}
