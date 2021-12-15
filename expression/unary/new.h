
struct types;
enum unary_expression_kind;
struct expression;

#include "kind.h"

int new_unary_expression(
	struct expression** new,
	enum unary_expression_kind kind,
	struct expression* inner,
	struct types* types);
