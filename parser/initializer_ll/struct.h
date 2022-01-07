
struct initializer_ll_link
{
	struct initializer* element;
	struct initializer_ll_link* next;
};

struct initializer_ll
{
	struct initializer_ll_link* head, *tail;
};

