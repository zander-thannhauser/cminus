
struct expression;
struct types;

int new_logical_and_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* left,
	struct expression* right,
	struct types* types);
