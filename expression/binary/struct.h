
#include <stdbool.h>

#include "../struct.h"

#include "kind.h"

struct binary_expression
{
	struct expression super;
	enum binary_expression_kind kind;
	bool is_integer_result;
	struct expression* left, *right;
};

