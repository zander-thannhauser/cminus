
struct types;
struct statement;
struct expression;

int selection_statement_if_callback(
	struct statement** out,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case,
	struct types* types);
