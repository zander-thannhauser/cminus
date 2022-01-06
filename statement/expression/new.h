
struct expression_statement;
struct expression;

int new_expression_statement(
	struct expression_statement** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression);
