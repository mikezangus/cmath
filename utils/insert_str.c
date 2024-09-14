#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool is_pos_inside_dest(char* dest_str, size_t dest_len, const char* insert_pos)
{
    return (insert_pos >= dest_str) && (insert_pos < dest_str + dest_len);
}

static void expand(char* dest_str, size_t dest_len, const char* insert_pos, size_t insert_len)
{
    const char* copy = dest_str + dest_len;
    char* paste = dest_str + dest_len + insert_len;
    while (copy >= insert_pos) {
        *paste-- = *copy--;
    }
}

static void insert(const char* insert_str, char* insert_pos)
{
    while (*insert_str) {
        *insert_pos++ = *insert_str++;
    }
}

void insert_str(char* dest_str, const char* insert_str, char* insert_pos)
{
    size_t dest_len = strlen(dest_str);
    if (!is_pos_inside_dest(dest_str, dest_len, insert_pos)) {
        fprintf(
            stderr,
            "insert_str(): insert_pos not inside of dest_str\n  dest_str: %p - %p\n  insert_pos: %p\n",
            dest_str, dest_str + dest_len, insert_pos);
        return;
    }
    expand(dest_str, dest_len, insert_pos, strlen(insert_str));
    insert(insert_str, insert_pos);
}
