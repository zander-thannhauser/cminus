
struct variable_link
{
	struct variable* element;
	struct variable_link* next;
};

struct variable_ll
{
	struct variable_link *head, *tail;
};

