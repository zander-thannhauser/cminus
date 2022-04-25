
#include <stdio.h>

#include <assert.h>

#include <defines/argv0.h>

#include "usage.h"

void usage()
{
	printf("usage: %s <path/to/input/file.cm> -o <path/to/output/file.png>\n", argv0);
}

