
#include "../struct.h"

struct addressof_expression
{
	struct expression super;
	
	struct expression* inner;
};

