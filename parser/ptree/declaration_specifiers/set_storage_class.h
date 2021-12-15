
#include <enums/storage_class.h>

struct declaration_specifiers;
enum storage_class;

int declaration_specifiers_set_storage_class(
	struct declaration_specifiers* this,
	enum storage_class storage_class);
