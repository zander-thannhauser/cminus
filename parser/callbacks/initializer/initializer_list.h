
struct initializer;
struct initializer_ll;

int initializer_initializer_list_callback(
	struct initializer** out,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct initializer_ll* list);
