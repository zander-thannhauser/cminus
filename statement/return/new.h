
struct return_statement;
struct expression;

int new_return_statement(
	struct return_statement** new,
	unsigned line,
	struct expression* expression);
