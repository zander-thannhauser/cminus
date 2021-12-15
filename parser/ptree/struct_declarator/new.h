
struct struct_declarator;
struct declarator;
struct expression;

int new_struct_declarator(
	struct struct_declarator** out,
	struct declarator* declarator,
	struct expression* bitfield_width);
