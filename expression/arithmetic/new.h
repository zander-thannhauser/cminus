
enum arithmetic_expression_kind;
struct expression;
struct types;

#include "kind.h"

int new_arithmetic_expression(
	struct expression** new,
	struct yylloc* loc,
	enum arithmetic_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types);
