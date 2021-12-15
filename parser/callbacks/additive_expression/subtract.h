
struct expression;
struct types;

int additive_expression_subtract_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types);
