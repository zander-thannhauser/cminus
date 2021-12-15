
struct types;
struct expression;
enum unary_expression_kind;

#include <expression/unary/kind.h>

int unary_expression_operator(
	struct expression** out,
	enum unary_expression_kind kind,
	struct expression* inner,
	struct types* types);
