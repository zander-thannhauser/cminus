
struct types;
struct type;
struct expression;

int new_cast_expression(
	struct expression** new,
	struct type* type,
	struct expression* inner,
	struct types* types);
