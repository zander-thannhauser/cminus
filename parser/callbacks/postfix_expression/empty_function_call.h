
struct expression;

int postfix_expression_empty_function_call_callback(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* function_expression);
	
	
