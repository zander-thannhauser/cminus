
struct expression;
struct types;

int new_logical_or_expression(
	struct expression** new,
	struct expression* left,
	struct expression* right,
	struct types* types);
