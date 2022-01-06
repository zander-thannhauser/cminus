
enum assign_expression_kind;
struct expression;
struct types;

#include "kind.h"

int new_assign_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	enum assign_expression_kind kind,
	struct expression* left,
	struct expression* right,
	struct types* types);
