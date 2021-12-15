
struct pointer;
struct declarator;

int new_pointer_declarator_from_pointer(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* inner);
