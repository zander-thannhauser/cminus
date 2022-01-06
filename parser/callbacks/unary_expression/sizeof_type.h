
struct expression;
struct type;
struct types;

int unary_expression_sizeof_type_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* type,
	struct types* types);
