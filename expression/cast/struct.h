
#include "../struct.h"

struct cast_expression
{
	struct expression super;
	
	struct type* type;
	
	struct expression* inner;
};

