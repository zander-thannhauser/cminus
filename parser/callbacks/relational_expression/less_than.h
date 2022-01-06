
struct expression;
struct types;

int relational_expression_less_than_callback(
	struct expression** out,
	struct expression* left,
	struct expression* right,
	struct types* types);
