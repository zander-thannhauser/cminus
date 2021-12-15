
struct expression;

#include "../struct.h"

struct return_statement
{
	struct statement super;
	
	bool is_integer_result;
	
	char* funcname;
	struct expression* return_value; // optional
};

