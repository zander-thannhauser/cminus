
struct declarator;
struct parameter_ll;

int direct_declarator_parameter_list_callback(
	struct declarator** out,
	struct declarator* inner,
	struct parameter_ll* params);
