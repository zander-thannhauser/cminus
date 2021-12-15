
#include <stdlib.h>

#include <debug.h>

#include "free.h"

void free_flags(struct cmdln_flags* flags)
{
	free(flags);
}

