
struct function_call_expression;
struct expression;
struct expression_ll;
struct types;
struct yylloc;

int new_function_call_expression(
	struct function_call_expression** new,
	struct yylloc* loc,
	struct expression* fe,
	struct expression_ll* casted_args);
