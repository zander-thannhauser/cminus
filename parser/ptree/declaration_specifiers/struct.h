
#include <enums/type_qualifier.h>
#include <enums/storage_class.h>

struct declaration_specifiers
{
	struct type* type;
	
	enum storage_class storage_class;
	
	struct type_qualifiers* qualifiers;
};
