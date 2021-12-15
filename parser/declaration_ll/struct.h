
struct declaration_link
{
	struct declaration* element;
	struct declaration_link* next;
};

struct declaration_ll
{
	struct declaration_link* head, *tail;
};
