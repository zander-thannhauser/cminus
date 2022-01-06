
struct variable_expression;
struct variable;

int new_variable_expression(
	struct variable_expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct variable* variable);




