
struct expression;

int postfix_expression_field_access_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* inner,
	char* field_name);



