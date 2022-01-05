
struct expression;
struct types;

int new_comma_expression(
	struct expression** new,
	struct expression* left,
	struct expression* right,
	struct types* types);
