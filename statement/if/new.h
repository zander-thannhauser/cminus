
struct types;
struct if_statement;
struct expression;
struct statement;
struct yylloc;

int new_if_statement(
	struct if_statement** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case);




