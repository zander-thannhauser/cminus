
#include <stdlib.h>
#include <enums/storage_class.h>

struct function_definition
{
	char* name;
	struct function_type* ftype;
	enum storage_class storage_class;
	struct variable_ll* parameters;
	struct compound_statement* body;
	size_t frame_size;
};

