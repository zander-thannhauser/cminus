
#include <stdbool.h>

#include "../struct.h"

struct logical_or_expression
{
	struct expression super;
	
	struct expression* left, *right;
};

