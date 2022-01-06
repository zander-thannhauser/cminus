
struct function_call_expression;
struct expression;
struct expression_ll;
struct types;

int new_function_call_expression(
	struct function_call_expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* function_expression,
	struct expression_ll* expressions);
