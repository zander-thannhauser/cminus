
struct ternary_expression;
struct variable;

int new_ternary_expression(
	struct ternary_expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct expression* conditional,
	struct expression* true_expression,
	struct expression* false_expression);



