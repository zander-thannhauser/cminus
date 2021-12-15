
struct expression;

int equality_expression_equal_to_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
