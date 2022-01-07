
struct expression;
struct types;

int primary_expression_uinteger_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	unsigned int uintegerlit);
