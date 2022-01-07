
struct init_declarator;
struct declarator;
struct initializer;

int init_declarator_declarator_and_initializer_callback(
	struct init_declarator** out,
	struct declarator* declarator,
	struct initializer* initializer);
