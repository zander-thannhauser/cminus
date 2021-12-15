
struct types;
struct expression;

int additive_expression_add_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right,
	struct types* types);
