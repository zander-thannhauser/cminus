
struct types;
struct literal_expression;

#include "kind.h"

extern int (*binary_constfolders[number_of_binary_expressions])(
	struct literal_expression** outgoing,
	struct literal_expression* left,
	struct literal_expression* right, struct types*);
