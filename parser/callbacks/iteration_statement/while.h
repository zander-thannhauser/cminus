
struct types;
struct statement;
struct expression;

int iteration_statement_while_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional,
	struct statement* body);
