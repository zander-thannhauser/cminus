
struct expression_statement;
struct expression;

int new_expression_statement(
	struct expression_statement** new,
	unsigned line,
	struct expression* expression);
