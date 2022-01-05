
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct assign_expression
{
	struct expression super;
	
	enum assign_expression_kind kind;
	
	struct expression* left, *right;
};

