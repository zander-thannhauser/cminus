
#include <assert.h>

#include <memory/tmalloc.h>

#include "free.h"
#include "new.h"
#include "struct.h"

int new_yyloc(
	struct yylloc** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column)
{
	int error = 0;
	struct yylloc* this;
	ENTER;
	
	error = tmalloc((void**) &this, sizeof(*this), free_yyloc);
	
	if (!error)
	{
		this->first_line = first_line;
		this->first_column = first_column;
		this->last_line = last_line;
		this->last_column = last_column;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

