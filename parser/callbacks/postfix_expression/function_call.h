
struct expression;
struct expression_ll;
struct types;

int postfix_expression_function_call_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* function_expression,
	struct expression_ll* expressions,
	struct types* types);
