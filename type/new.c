
#include <string.h>

#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "kind.h"
#include "free.h"
#include "new.h"

int new_type(
	struct type** new,
	enum type_kind kind,
	struct type_inheritance* inheritance,
	bool is_complete,
	size_t size,
	size_t alloc_size)
{
	int error = 0;
	ENTER;
	
	struct type* this = NULL;
	
	error = tmalloc(
		(void**) &this,
		alloc_size,
		(void (*)(void*)) free_type);
	
	if (!error)
	{
		this->kind = kind;
		this->inheritance = inheritance;
		
		this->size = size;
		this->is_complete = is_complete;
		
		HERE;
		memset(this->qualifiers, false, sizeof(this->qualifiers));
		
		*new = this;
	}
	
	EXIT;
	return error;
}





















