
#include <stdio.h>
#include <stdbool.h>

#include <enums/type_qualifier.h>

struct type;
struct type_qualifiers;

struct type_inheritance
{
	bool (*is_equal)(const struct type*, const struct type*);
	int (*clone_with_qualifiers)(
		struct type**, const struct type*, bool[number_of_type_qualifiers]);
	void (*print)(const struct type*, FILE* stream);
	void (*free)(struct type*);
};

