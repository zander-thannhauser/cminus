
struct statement_ll;
struct statement;

int statement_list_append_callback(
	struct statement_ll** retval,
	struct statement_ll* list,
	struct statement* element);
