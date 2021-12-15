
struct expression_ll;
struct expression;

int argument_expression_list_append_callback(
	struct expression_ll** retval,
	struct expression_ll* list,
	struct expression* expression);
