
struct types;
struct expression;
enum unary_expression_kind;

#include <enums/unary_kind.h>

int unary_expression_operator(
	struct expression** out,
	enum unary_expression_kind kind,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner);
