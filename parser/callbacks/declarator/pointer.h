
struct pointer;
struct declarator;

int declarator_pointer_callback(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* inner);
