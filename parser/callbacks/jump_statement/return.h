
struct statement;
struct expression;

int jump_statement_return_callback(
	struct statement** out,
	unsigned line,
	struct type* rettype,
	struct expression* expression,
	struct types* types,
	char* name);
