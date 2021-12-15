
#include <enums/storage_class.h>

struct scope;
struct type;
struct variable;

int scope_declare_variable(
	struct scope* this,
	char* identifier,
	struct type* type,
	enum storage_class storage_class,
	struct variable** outgoing);
