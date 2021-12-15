
struct function_call_expression;
struct expression;
struct expression_ll;
struct types;

int new_function_call_expression(
	struct function_call_expression** retval,
	struct expression* function_expression,
	struct expression_ll* expressions,
	struct types* types);
