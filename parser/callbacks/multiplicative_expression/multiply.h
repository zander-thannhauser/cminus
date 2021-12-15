
struct expression;
struct types;

int multiplicative_expression_multiply_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types);
