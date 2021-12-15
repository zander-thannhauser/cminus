
#include <stdbool.h>

struct struct_type;
struct struct_field_ll;

int new_struct_type(
	struct struct_type** new,
	bool struct_or_union,
	struct struct_field_ll* fields);

int new_incomplete_struct_type(
	struct struct_type** new,
	bool struct_or_union);
