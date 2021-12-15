
struct types;
struct if_statement;
struct expression;
struct statement;

int new_if_statement(
	struct if_statement** new,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case,
	struct types* types);
