
struct statement_link
{
	struct statement* element;
	struct statement_link* next;
};

struct statement_ll
{
	struct statement_link *head, *tail;
};

