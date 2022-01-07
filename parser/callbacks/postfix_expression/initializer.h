
struct expression;
struct type;
struct initializer_ll;
struct scope;

int postfix_expression_initializer_callback(
	struct expression** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct scope* scope,
	struct type* type,
	struct initializer_ll* initializer_ll);






