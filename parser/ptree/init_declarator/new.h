
struct init_declarator;
struct declarator;
struct initializer;

int new_init_declarator(
	struct init_declarator** new,
	struct declarator* declarator,
	struct initializer* initializer);
