
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct arithmetic_expression
{
	struct expression super;
	
	enum arithmetic_expression_kind kind;
	
	bool is_float_result;
	
	struct expression* left, *right;
};

