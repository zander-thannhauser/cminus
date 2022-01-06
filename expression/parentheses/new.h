
struct expression;

int new_parentheses_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner);
