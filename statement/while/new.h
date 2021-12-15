
struct types;
struct while_statement;
struct expression;
struct statement;

int new_while_statement(
	struct while_statement** new,
	struct expression* conditional,
	struct statement* body,
	struct types* types);
