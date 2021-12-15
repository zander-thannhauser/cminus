
#include <sys/types.h>
#include <stdbool.h>

#include <enums/storage_class.h>

struct variable
{
	char* name; // must be the first
	
	off_t offset;
	
	struct type* type;
	
	enum storage_class storage_class;
	
	bool is_global;
};

