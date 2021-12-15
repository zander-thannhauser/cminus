
#include <stddef.h>

int tmalloc(void** retval, size_t size, void (*destructor)(void*));
