#include "../algebraic.h"
#include "../../../main.h"

void isolate(char* s)
{
    isolate_num_oprtn(s);
    isolate_var_base(s);
    isolate_var_exp(s);
}
