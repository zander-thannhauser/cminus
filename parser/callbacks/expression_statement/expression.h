
struct statement;
struct expression;

int expression_statement_expression_callback(
	struct statement** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* expression);
