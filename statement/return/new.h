
struct return_statement;
struct expression;
struct type;

int new_return_statement(
	struct return_statement** new,
	struct yylloc* loc,
	bool is_integer_result,
	char* name,
	struct expression* expression);
