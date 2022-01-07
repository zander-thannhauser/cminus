
#include "../struct.h"

struct parentheses_expression
{
	struct expression super;
	
	struct expression* inner;
};

