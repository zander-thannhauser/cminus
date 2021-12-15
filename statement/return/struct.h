
struct expression;

#include "../struct.h"

struct return_statement
{
	struct statement super;
	struct expression* return_value; // optional
};

