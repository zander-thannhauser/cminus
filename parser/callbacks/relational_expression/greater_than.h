
struct types;
struct expression;

int relational_expression_greater_than_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
