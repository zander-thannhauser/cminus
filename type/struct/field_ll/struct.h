
struct struct_field_ll_link
{
	struct struct_field* element;
	struct struct_field_ll_link* next;
};

struct struct_field_ll
{
	struct struct_field_ll_link* head, *tail;
};

