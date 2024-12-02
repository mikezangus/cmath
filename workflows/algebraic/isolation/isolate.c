#include "../algebraic.h"
#include "../../../main.h"
#include "../../../formatting/formatting.h"

void isolate(char* s, Bounds* b)
{
    isolate_num_oprtn(s, b);
    isolate_var_base(s, b);
    isolate_var_exp(s, b);
}
