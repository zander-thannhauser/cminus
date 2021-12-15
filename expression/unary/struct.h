
#include "../struct.h"

#include "kind.h"

struct unary_expression
{
	struct expression super;
	enum unary_expression_kind kind;
	struct expression* inner;
};

