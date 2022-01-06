
/*#include <stdbool.h>*/

#include "../struct.h"

struct ternary_expression
{
	struct expression super;
	
	struct expression* conditional;
	struct expression* true_expression;
	struct expression* false_expression;
};

