
struct types;
struct statement;
struct expression;

int iteration_statement_while_callback(
	struct statement** out,
	struct expression* conditional,
	struct statement* body,
	struct types* types);
