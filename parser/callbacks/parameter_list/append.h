
struct parameter_ll;
struct parameter;

int parameter_list_append_callback(
	struct parameter_ll** out,
	struct parameter_ll* list,
	struct parameter* appendme);
