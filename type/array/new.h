
struct array_type;
struct type;
struct expression;

int new_array_type(
	struct array_type** new,
	struct type* retval,
	size_t size);


int new_sizeless_array_type(
	struct array_type** new,
	struct type* element_type);
