
struct expression;
struct type;

int cast_expression_cast_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* type,
	struct expression* inner);
