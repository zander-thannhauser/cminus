
struct initializer_ll;
struct initializer;

int initializer_list_append_callback(
	struct initializer_ll** out,
	struct initializer_ll* list,
	struct initializer* element);
