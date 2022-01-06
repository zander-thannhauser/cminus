
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct comparision_expression
{
	struct expression super;
	
	enum comparision_expression_kind kind;
	
	bool is_float_result;
	
	struct expression* left, *right;
};

