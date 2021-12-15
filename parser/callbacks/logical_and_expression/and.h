
struct types;
struct expression;

int logical_and_expression_and_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
