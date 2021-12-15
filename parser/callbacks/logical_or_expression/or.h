
struct expression;

int logical_or_expression_or_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
