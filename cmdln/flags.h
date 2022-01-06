
#include <stdbool.h>

struct cmdln_flags
{
	bool preprocess;
	
	const char* input_path;
	const char* output_path;
};
