
struct init_declarator_ll;
struct init_declarator;

int init_declarator_ll_append_callback(
	struct init_declarator_ll** retval,
	struct init_declarator_ll* list,
	struct init_declarator* element);
