
struct expression;

#include "../struct.h"

struct expression_statement
{
	struct statement super;
	struct expression* expression;
};

