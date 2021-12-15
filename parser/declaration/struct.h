
enum storage_class;
struct type;

#include <enums/storage_class.h>

struct declaration
{
	enum storage_class storage_class;
	struct type* type;
	char* identifier;
};
