
struct init_declarator_ll_link
{
	struct init_declarator* element;
	struct init_declarator_ll_link* next;
};

struct init_declarator_ll
{
	struct init_declarator_ll_link* head, *tail;
};

