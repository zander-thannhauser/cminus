
#include "../struct.h"

struct comma_expression
{
	struct expression super;
	
	struct expression* left, *right;
};

