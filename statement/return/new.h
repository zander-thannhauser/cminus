
struct return_statement;
struct expression;
struct type;

int new_return_statement(
	struct return_statement** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	bool is_integer_result,
	char* name,
	struct expression* expression);
