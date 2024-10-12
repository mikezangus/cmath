void copy_bounded_str(char* dst,
                      char* src_start,
                      char* src_end)
{
    for (char* p = src_start;
         *p && p <= src_end;
         p++, dst++)
    {
        *dst = *p;
    }
    *dst =  '\0';
}
