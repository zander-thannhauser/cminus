
struct types;
struct literal_expression;

#include "kind.h"

extern int (*arithmetic_constfolders[number_of_arithmetic_expressions])(
	struct literal_expression** outgoing,
	struct literal_expression* left,
	struct literal_expression* right,
	struct yylloc*,
	struct types*);
