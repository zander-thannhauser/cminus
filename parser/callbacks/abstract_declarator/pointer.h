
struct declarator;
struct pointer;

int abstract_declarator_pointer_callback(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* maybe_inner);
