
struct type;
struct yylloc;
struct expression;
struct initializer;

int new_initializer_expression(
	struct expression** new,
	struct yylloc* loc,
	struct initializer* initializer,
	size_t offset,
	struct type* type);



