
struct function_declarator;
struct declarator;
struct parameter_ll;

int new_function_declarator(
	struct function_declarator** new,
	struct declarator* inner,
	struct parameter_ll* parameters);
