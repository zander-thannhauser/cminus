
struct struct_declarator_ll_link
{
	struct struct_declarator* element;
	struct struct_declarator_ll_link* next;
};

struct struct_declarator_ll
{
	struct struct_declarator_ll_link* head, *tail;
};

