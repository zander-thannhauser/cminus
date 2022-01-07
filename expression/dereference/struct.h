
#include "../struct.h"

struct dereference_expression
{
	struct expression super;
	
	struct expression* inner;
};

