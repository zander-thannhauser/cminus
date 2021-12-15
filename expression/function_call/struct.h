
#include "../struct.h"

struct function_call_expression
{
	struct expression super;
	struct expression* function;
	struct expression_ll* arguments;
};

