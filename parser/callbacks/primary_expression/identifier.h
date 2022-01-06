
struct scope;
struct expression;

int primary_expression_identifier_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct scope* scope,
	char* identifier);
