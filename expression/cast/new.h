
struct types;
struct type;
struct expression;

int new_cast_expression(
	struct expression** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct type* type,
	struct expression* inner,
	struct types* types);
