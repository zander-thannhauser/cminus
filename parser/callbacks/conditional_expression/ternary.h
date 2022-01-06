
struct expression;

int conditional_expression_ternary_callback(
	struct expression** out_expression,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional_expression,
	struct expression* true_expression,
	struct expression* false_expression);
