
struct statement;
struct expression;

int expression_statement_expression_callback(
	struct statement** retval,
	unsigned line,
	struct expression* expression);
