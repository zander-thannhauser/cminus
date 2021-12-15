
struct types;
struct expression;

int equality_expression_not_equal_to_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
