
struct expression_link
{
	struct expression* element;
	struct expression_link *prev, *next;
};

struct expression_ll
{
	struct expression_link* head, *tail;
};

