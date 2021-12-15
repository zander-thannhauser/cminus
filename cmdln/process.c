
#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "flags.h"
#include "usage.h"
#include "process.h"

int process_cmdln(struct cmdln_flags** retval, int argc, char* const* argv)
{
	int error = 0;
	ENTER;
	
	const char* input_path = NULL;
	const char* output_path = NULL;
	
	// for getopt:
	int opt, option_index;
	const struct option long_options[] = {
		{"output", required_argument, 0, 'o'},
		{0, 0, 0, 0}
	};
	
	while (!error && (opt = getopt_long(argc, argv, "o:", long_options, &option_index)) >= 0)
	{
		switch (opt)
		{
			case 'o':
				output_path = optarg;
				break;
			
			default:
				error = e_bad_cmdline_args;
				break;
		}
	}
	
	if (!error && !output_path)
	{
		fprintf(stderr, "%s: output file not specified!\n", argv0);
		error = e_bad_cmdline_args;
	}
	
	if (!error && optind == argc)
	{
		fprintf(stderr, "%s: input file not specified!\n", argv0);
		error = e_bad_cmdline_args;
	}
	
	if (error == e_bad_cmdline_args)
		usage();
	
	if (!error)
	{
		input_path = argv[optind++];
	}
	
	struct cmdln_flags* flags = NULL;
	
	if (!error)
		error = tmalloc((void**) &flags, sizeof(*flags), NULL);
	
	if (!error)
	{
		flags->input_path = input_path;
		flags->output_path = output_path;
		
		*retval = tinc(flags);
	}
	
	tfree(flags);
	
	EXIT;
	return error;
}











