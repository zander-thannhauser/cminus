
#include <stdbool.h>

#include "../struct.h"

struct variable_expression
{
	struct expression super;
	
	struct variable* variable;
	
	bool is_array;
};

