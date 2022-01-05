
#include <stdbool.h>

struct expression;

#include "../struct.h"

struct return_statement
{
	struct statement super;
	
	bool is_float_result;
	
	char* funcname;
	struct expression* return_value; // optional
};

