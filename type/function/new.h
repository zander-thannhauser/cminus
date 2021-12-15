
struct function_type;
struct type;
struct parameter_ll;

int new_function_type(
	struct function_type** new,
	struct type* retval,
	struct parameter_ll* parameters);
