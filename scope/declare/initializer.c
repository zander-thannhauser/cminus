
#include <assert.h>

#include "../struct.h"
#include "initializer.h"

int scope_declare_initializer(
	size_t* offset,
	struct scope* this,
	size_t size)
{
	int error = 0;
	ENTER;
	
	assert(this->stackhead);
	
	if ((*offset = this->stackhead->offset += size) > this->frame_size)
		this->frame_size = *offset;
	
	dpv(*offset);
	
	EXIT;
	return error;
}
