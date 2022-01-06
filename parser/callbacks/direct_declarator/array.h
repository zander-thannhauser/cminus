
struct types;
struct declarator;
struct expression;

int direct_declarator_array_callback(
	struct declarator** new,
	struct declarator* inner,
	struct expression* size_expression,
	struct types* types);
