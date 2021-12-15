
struct declarator;
struct expression;

int direct_declarator_array_callback(
	struct declarator** new,
	struct declarator* inner,
	struct expression* constant_expression);
