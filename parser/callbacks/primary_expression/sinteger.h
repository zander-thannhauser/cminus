
struct expression;
struct types;

int primary_expression_sinteger_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	signed int sintegerlit);
