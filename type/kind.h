
#ifndef TYPE_KIND_ENUM
#define TYPE_KIND_ENUM

// roughly ordered by promotion rules:

enum type_kind
{
	tk_integer,
	tk_pointer,
	tk_float,
	
	// these don't really have an order:
	tk_array,
	tk_struct,
	tk_function,
	tk_void,
};

#endif // TYPE_KIND_ENUM
