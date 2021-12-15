
#include <stdbool.h>

struct parameter_link
{
	struct parameter* element;
	struct parameter_link* next;
};


struct parameter_ll
{
	struct parameter_link* head, *tail;
	bool ellipsis;
};

