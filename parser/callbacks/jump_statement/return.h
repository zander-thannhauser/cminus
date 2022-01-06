
struct statement;
struct expression;

int jump_statement_return_callback(
	struct statement** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* rettype,
	struct expression* expression,
	struct types* types,
	char* name);
