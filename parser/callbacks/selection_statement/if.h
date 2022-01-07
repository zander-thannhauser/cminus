
struct types;
struct statement;
struct expression;

int selection_statement_if_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case);



