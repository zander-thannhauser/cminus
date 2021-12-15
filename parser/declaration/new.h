
struct declaration;
enum storage_class;
struct type;

#include <enums/storage_class.h>

int new_declaration(
	struct declaration** new,
	enum storage_class storage_class,
	struct type* type,
	char* identifier);
