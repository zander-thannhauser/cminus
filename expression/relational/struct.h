
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct relational_expression
{
	struct expression super;
	
	enum relational_expression_kind kind;
	
	bool comparing_floats;
	
	struct expression* left, *right;
};

