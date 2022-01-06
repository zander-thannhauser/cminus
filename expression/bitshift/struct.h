
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct bitshift_expression
{
	struct expression super;
	
	enum bitshift_expression_kind kind;
	
	bool is_float_result;
	
	struct expression* left, *right;
};

