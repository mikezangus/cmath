void copy_bounded_str(char *input_start, char *input_end, char *output)
{
    for (char *p = input_start; *p && p <= input_end; p++, output++) {
        *output = *p;
    }
    *output =  '\0';
}
