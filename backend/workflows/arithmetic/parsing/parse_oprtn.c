#include <string.h>

void parse_oprtn(char* dst_op1, char* dst_oprtr, char* dst_op2,
                 const char* src_op1, char src_oprtr, const char* src_op2)
{
    strcpy(dst_op1, src_op1);
    strcpy(dst_op2, src_op2);
    if (dst_oprtr && src_oprtr) {
        *dst_oprtr = src_oprtr;
    }
}
