
#include <enums/storage_class.h>

struct declaration_specifiers;

int declaration_specifiers_storage_class_callback(
	struct declaration_specifiers** retval,
	enum storage_class storage_class,
	struct declaration_specifiers* declaration_specifiers);
