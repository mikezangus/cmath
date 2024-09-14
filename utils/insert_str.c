#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool pos_is_inside_dest(char* dest_str, char* insert_pos)
{
    return (insert_pos >= dest_str) && (insert_pos < dest_str + strlen(dest_str));
}

static void expand(char* dest_str, int insert_len, char* insert_pos)
{
    int dest_len = strlen(dest_str);
    char* copy = dest_str + dest_len;
    char* paste = dest_str + dest_len + insert_len;
    for (; copy >= insert_pos; copy--, paste--) {
        *paste = *copy;
    }
}

static void insert(const char* insert_str, char* insert_pos)
{
    const char* copy = insert_str;
    char* paste = insert_pos;
    while (*copy) {
        *paste++ = *copy++;
    }
}

void insert_str(char* dest_str, const char* insert_str, char* insert_pos)
{
    int insert_len = strlen(insert_str);
    if (!pos_is_inside_dest(dest_str, insert_pos)) {
        fprintf(
            stderr,
            "insert_str(): insert_pos not inside of dest_str\n  insert_str: %p - %p\n  insert_pos: %p\n",
            insert_str, insert_str + insert_len, insert_pos);
        return;
    }
    expand(dest_str, insert_len, insert_pos);
    insert(insert_str, insert_pos);
}
