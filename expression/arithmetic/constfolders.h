
struct types;
struct literal_expression;

#include "kind.h"

extern int (*arithmetic_constfolders[number_of_arithmetic_expressions])(
	struct literal_expression** outgoing,
	struct literal_expression* left,
	struct literal_expression* right,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct types*);
