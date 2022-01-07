
struct yylloc;
struct types;
struct type;
struct expression;

int new_cast_expression(
	struct expression** new,
	struct yylloc* loc,
	struct type* after,
	struct expression* inner);
