
struct initializer;
struct expression;

int initializer_expression_callback(
	struct initializer** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression);
