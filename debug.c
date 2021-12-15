
/*#ifdef DEBUGGING*/
#if 0

#define UNW_LOCAL_ONLY
#include <libunwind.h>

#include <debug.h>

#if 0

void show_backtrace (void) {
  unw_cursor_t cursor; unw_context_t uc;
  unw_word_t ip, sp;

  unw_getcontext(&uc);
  unw_init_local(&cursor, &uc);
  while (unw_step(&cursor) > 0) {
    unw_get_reg(&cursor, UNW_REG_IP, &ip);
    unw_get_reg(&cursor, UNW_REG_SP, &sp);
    printf ("ip = %lx, sp = %lx\n", (long) ip, (long) sp);
  }
}
#endif

#define PRINT_WRAPPER_CALLS

FILE* __real_fopen(const char* path, const char* mode);
FILE* __real_fdopen(int fd, const char* mode);
int   __real_fclose(FILE* stream);

int __real_open(const char *pathname, int flags, mode_t mode);
int __real_creat(const char *pathname, mode_t mode);
int __real_openat(int dirfd, const char *pathname, int flags, mode_t mode);
int __real_close(int fd);
int __real_pipe2(int pipefd[2], int flags);

void* __real_malloc(size_t size);
void* __real_realloc(void* ptr, size_t size);
void  __real_free(void* ptr);


static void who_called(char** outgoing)
{
	char name[100], appendme[120];
	struct {
		char* data;
		size_t n, cap;
	} buffer = {};
	
	void strcat(const char* string, size_t len)
	{
		while (buffer.n + len >= buffer.cap)
		{
			buffer.cap = buffer.cap * 2 ?: 1;
			buffer.data = __real_realloc(buffer.data, buffer.cap);
			
			assert(buffer.data);
		}
		
		memcpy(&buffer.data[buffer.n], string, len);
		buffer.n += len;
	}
	
	unw_context_t uc;
	unw_cursor_t cursor;
	unw_word_t offp;
	
	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);
	
	unw_step(&cursor);
	
	while (unw_step(&cursor) > 0)
	{
		assert(!unw_get_proc_name(&cursor, name, sizeof(name), &offp));
		
		// dpvs(name);
		
		strcat(appendme, snprintf(appendme, sizeof(appendme), "%s%s()",
			buffer.n > 0 ? ", in " : "", name));
		
		if (!strcmp(name, "main"))
			break;
	}
	
	strcat("", 1);
	
	*outgoing = buffer.data;
	
	// dpvs(*outgoing);
}

static struct {
	struct {
		FILE* stream;
		char* stacktrace;
	}* data;
	size_t n, cap;
} files = {NULL, 0, 0};

static struct {
	struct {
		char* stacktrace;
		bool is_open;
	}* data;
	size_t n;
} fds = {NULL, 0};

static void __file_add(FILE* stream, char* stacktrace)
{
	if (files.n + 1 >= files.cap)
	{
		files.cap = files.cap * 2 ?: 1;
		files.data = __real_realloc(files.data, sizeof(*files.data) * files.cap);
		
		assert(files.data);
	}
	
	files.data[files.n].stream = stream;
	files.data[files.n].stacktrace = stacktrace;
	files.n++;
	
	dpv(files.n);
}

static void __file_rm(FILE* stream)
{
	bool found;
	size_t i, n;
	
	assert(files.n);
	
	for (i = 0, n = files.n, found = false; i < n; i++)
		if (found)
			files.data[i - 1] = files.data[i];
		else if (files.data[i].stream == stream)
		{
			__real_free(files.data[i].stacktrace);
			found = true;
		}
	
	if (!found)
	{
		dpv(stream);
		assert(found);
	}
	
	files.n--;
}

FILE* __wrap_fopen(const char* path, const char* mode)
{
	FILE* retval;
	char* stacktrace;
	
	retval = __real_fopen(path, mode);
	
	if (retval)
	{
		who_called(&stacktrace);
		__file_add(retval, stacktrace);
	}
	
	return retval;
}

FILE* __wrap_fdopen(int fd, const char* mode)
{
	FILE* retval;
	char* stacktrace;
	
	retval = __real_fdopen(fd, mode);
	
	if (retval)
	{
		fds.data[fd].is_open = false;
		
		who_called(&stacktrace);
		__file_add(retval, stacktrace);
	}
	
	return retval;
}

int __wrap_fclose(FILE* stream)
{
	int retval = __real_fclose(stream);
	
	if (!retval)
	{
		__file_rm(stream);
	}
	
	return retval;
}

void  __attribute__ ((destructor)) __file_printout()
{
	int i, n;
	
	for (i = 0, n = files.n; i < n; i++)
	{
		ddprintf("unclosed FILE* %p, opened by %s\n", files.data[i].stream, files.data[i].stacktrace);
	}
	
	__real_free(files.data);
}

#ifdef PRINT_WRAPPER_CALLS
static void flags_to_str(char* out, int flags)
{
	if (flags & O_WRONLY) strcat(out, "O_WRONLY | "), flags &= ~O_WRONLY;
	if (flags & O_RDWR)   strcat(out, "O_RDWR | "),   flags &= ~O_RDWR;
	
	if (flags & O_APPEND)    strcat(out, "O_APPEND | "),    flags &= ~O_APPEND;
	if (flags & O_ASYNC)     strcat(out, "O_ASYNC | "),     flags &= ~O_ASYNC;
	if (flags & O_CLOEXEC)   strcat(out, "O_CLOEXEC | "),   flags &= ~O_CLOEXEC;
	if (flags & O_CREAT)     strcat(out, "O_CREAT | "),     flags &= ~O_CREAT;
	if (flags & O_DIRECT)    strcat(out, "O_DIRECT | "),    flags &= ~O_DIRECT;
	if (flags & O_DIRECTORY) strcat(out, "O_DIRECTORY | "), flags &= ~O_DIRECTORY;
	if (flags & O_DSYNC)     strcat(out, "O_DSYNC | "),     flags &= ~O_DSYNC;
	if (flags & O_EXCL)      strcat(out, "O_EXCL | "),      flags &= ~O_EXCL;
	if (flags & O_LARGEFILE) strcat(out, "O_LARGEFILE | "), flags &= ~O_LARGEFILE;
	if (flags & O_NOATIME)   strcat(out, "O_NOATIME | "),   flags &= ~O_NOATIME;
	if (flags & O_NOCTTY)    strcat(out, "O_NOCTTY | "),    flags &= ~O_NOCTTY;
	if (flags & O_NOFOLLOW)  strcat(out, "O_NOFOLLOW | "),  flags &= ~O_NOFOLLOW;
	if (flags & O_NONBLOCK)  strcat(out, "O_NONBLOCK | "),  flags &= ~O_NONBLOCK;
	if (flags & O_PATH)      strcat(out, "O_PATH | "),      flags &= ~O_PATH;
	if (flags & O_SYNC)      strcat(out, "O_SYNC | "),      flags &= ~O_SYNC;
	if (flags & O_TMPFILE)   strcat(out, "O_TMPFILE | "),   flags &= ~O_TMPFILE;
	if (flags & O_TRUNC)     strcat(out, "O_TRUNC | "),     flags &= ~O_TRUNC;
	
	if (flags)
		strcpy(out, "@#?!");
	else
		out[strlen(out) - 3] = '\0';
}

#endif

static void __fd_add(int fd, char* stacktrace)
{
	if (fds.n <= fd)
	{
		size_t i, n = (fd + 1);
		
		fds.data = __real_realloc(fds.data, sizeof(*fds.data) * n);
		
		assert(fds.data);
		
		for (i = fds.n; i < n; i++)
			fds.data[i].is_open = false;
		
		fds.n = n;
	}
	
	fds.data[fd].stacktrace = stacktrace;
	fds.data[fd].is_open = true;
}

int __wrap_open(const char *pathname, int flags, mode_t mode)
{
	unw_cursor_t cursor; unw_context_t uc;
	char *name;
	int fd = __real_open(pathname, flags, mode);
	
	if (fd > 0)
	{
		who_called(&name);
		
		__fd_add(fd, name);
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	char fmt[200] = "\e[2m" "%2$*1$sopen(path = \"%3$s\"", buffer[200] = "";
	
	if (flags)
	{
		strcat(fmt, ", flags = %4$s");
		flags_to_str(buffer, flags);
	}
	
	if (flags & (O_CREAT | O_TMPFILE))
		strcat(fmt, ", mode = 0%5$o");
		
	strcat(fmt, ") = %6$i");
	
	if (fd < 0)
		strcat(fmt, " (%m)");
	
	strcat(fmt, "\e[0m" "\n");
	
	printf(fmt, debug_depth, "", pathname, buffer, mode, fd);
	#endif
	
	return fd;
}

int __wrap_creat(const char *pathname, mode_t mode)
{
	unw_cursor_t cursor; unw_context_t uc;
	char *name;
	int fd = __real_creat(pathname, mode);
	
	if (fd > 0)
	{
		who_called(&name);
		
		__fd_add(fd, name);
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	char fmt[200] = ""
		"\e[2m" "%2$*1$screat(path = \"%3$s\", mode = 0%4$o) = %5$i";
	
	if (fd < 0)
	{
		strcat(fmt, " (%m)");
	}
	
	strcat(fmt, "\e[0m" "\n");
	
	printf(fmt, debug_depth, "", pathname, mode, fd);
	#endif
	
	return fd;
}

int __wrap_pipe2(int pipefd[2], int flags)
{
	unw_cursor_t cursor;
	unw_context_t uc;
	char *name1, *name2;
	int retval = __real_pipe2(pipefd, flags);
	
	if (retval >= 0)
	{
		who_called(&name1);
		who_called(&name2);
		
		__fd_add(pipefd[0], name1);
		__fd_add(pipefd[1], name2);
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	char fmt[200] = "\e[2m" "%2$*1$spipe2(pipefd = {%3$i, %4$i}) = %5$i";
	
	if (retval < 0)
	{
		strcat(fmt, " (%m)");
	}
	
	strcat(fmt, "\e[0m" "\n");
	
	printf(fmt, debug_depth, "", pipefd[0], pipefd[1], retval);
	#endif
	
	return retval;
}

int __wrap_openat(int dirfd, const char *pathname, int flags, mode_t mode)
{
	char *name;
	int fd = __real_openat(dirfd, pathname, flags, mode);
	
	if (fd > 0)
	{
		who_called(&name);
		__fd_add(fd, name);
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	char fmt[200] = "\e[2m" "%2$*1$sopenat(dirfd = %3$i, path = \"%4$s\"", buffer[200] = "";
	
	if (flags)
	{
		strcat(fmt, ", flags = %5$s");
		flags_to_str(buffer, flags);
	}
	
	if (flags & (O_CREAT | O_TMPFILE))
		strcat(fmt, ", mode = 0%6$o");
		
	strcat(fmt, ") = %7$i");
	
	if (fd < 0)
		strcat(fmt, " (%m)");
	
	strcat(fmt, "\e[0m" "\n");
	
	printf(fmt, debug_depth, "", dirfd, pathname, buffer, mode, fd);
	#endif
	
	return fd;
}

int __wrap_close(int fd)
{
	int retval;
	
	dpv(fd);
	
	if (fd >= 0)
	{
		assert(fds.data[fd].is_open);
		
		__real_free(fds.data[fd].stacktrace);
		fds.data[fd].is_open = false;
	}
	
	retval = __real_close(fd);
	
	#ifdef PRINT_WRAPPER_CALLS
	char fmt[200] = "%2$*1$s";
	
	strcat(fmt, "\e[2m");
	
	strcat(fmt, "close(fd = %3$i)");
	
	if (retval < 0)
		strcat(fmt, " = %4$i (%m)");
	else
		strcat(fmt, ";");
	
	strcat(fmt, "\e[0m");
	strcat(fmt, "\n");
	
	printf(fmt, debug_depth, "", fd, retval);
	#endif
	
	return retval;
}

void  __attribute__ ((destructor)) __filedes_printout()
{
	int i, n;
	
	for (i = 0, n = fds.n; i < n; i++)
	{
		if (fds.data[i].is_open)
		{
			ddprintf("unclosed file descriptor %i, opened by %s\n", i, fds.data[i].stacktrace);
		}
	}
	
	__real_free(fds.data);
}

static struct {
	struct {
		void* ptr;
		char* stacktrace;
	}* data;
	size_t n, cap;
} ptrs = {NULL, 0, 0};

static void __mem_add(void* ptr, char* stacktrace)
{
	if (ptrs.n + 1 >= ptrs.cap)
	{
		ptrs.cap = ptrs.cap * 2 ?: 1;
		ptrs.data = __real_realloc(ptrs.data, sizeof(*ptrs.data) * ptrs.cap);
		
		assert(ptrs.data);
	}
	
	ptrs.data[ptrs.n].ptr = ptr;
	ptrs.data[ptrs.n].stacktrace = stacktrace;
	
	ptrs.n++;
}

static void __mem_rm(void* ptr)
{
	bool found;
	size_t i, n;
	
	assert(ptrs.n);
	
	for (i = 0, n = ptrs.n, found = false; i < n; i++)
		if (found)
			ptrs.data[i - 1] = ptrs.data[i];
		else if (ptrs.data[i].ptr == ptr)
		{
			__real_free(ptrs.data[i].stacktrace);
			found = true;
		}
	
	if (!found)
	{
		dpv(ptr);
		assert(found);
	}
	
	ptrs.n--;
}

void* __wrap_malloc(size_t size)
{
	char* stacktrace;
	void* ptr = __real_malloc(size);
	
	if (ptr)
	{
		who_called(&stacktrace);
		__mem_add(ptr, stacktrace);
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	ddprintf("\e[2m" "malloc(size = %lu) = %p" "\e[0m" "\n", size, ptr);
	#endif
	
	return ptr;
}


void* __wrap_realloc(void* ptr, size_t size)
{
	char *stacktrace;
	void* old = ptr;
	void* new = __real_realloc(ptr, size);
	
	if (old != new)
	{
		if (old)
			__mem_rm(old);
		
		if (new)
		{
			who_called(&stacktrace);
			__mem_add(new, stacktrace);
		}
	}
	
	#ifdef PRINT_WRAPPER_CALLS
	ddprintf("\e[2m" "realloc(ptr = %p, size = %lu) = %p" "\e[0m" "\n", old, size, new);
	#endif
	
	return new;
}

void __wrap_free(void* ptr)
{
	if (ptr)
	{
		__real_free(ptr);
		__mem_rm(ptr);
		
		#ifdef PRINT_WRAPPER_CALLS
		ddprintf("\e[2m" "free(ptr = %p);" "\e[0m" "\n", ptr);
		#endif
	}
}

ssize_t __real_getline(char **lineptr, size_t *n, FILE *stream);

ssize_t __wrap_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *stacktrace;
	
	char* before = *lineptr;
	
	ssize_t retval = __real_getline(lineptr, n, stream);
	
	char* after = *lineptr;
	
	if (before != after)
	{
		if (before) __mem_rm(before);
		
		if (after)
		{
			who_called(&stacktrace);
			__mem_add(after, stacktrace);
		}
	}
	
	return retval;
}

void  __attribute__ ((destructor)) __memory_printout()
{
	size_t i, n;
	for (i = 0, n = ptrs.n; i < n; i++)
	{
		ddprintf("unfreed memory allocation %p, malloced by %s\n",
			ptrs.data[i].ptr, ptrs.data[i].stacktrace);
	}
	
	__real_free(ptrs.data);
}

#endif















