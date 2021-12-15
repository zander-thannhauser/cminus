
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_init_declarator(struct init_declarator* this)
{
	tfree(this->declarator);
	tfree(this->initializer);
}

