
struct types;
struct expression;

int additive_expression_add_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct expression* left,
	struct expression* right,
	struct types* types);
