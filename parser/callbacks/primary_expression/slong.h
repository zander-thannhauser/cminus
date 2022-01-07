
struct expression;
struct types;

int primary_expression_slong_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types* types,
	signed long slonglit);




