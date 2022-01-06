
#include <stdbool.h>
#include <stddef.h>

struct yylloc;
struct expression;
struct primitive_type;
struct type;

#if 0
int new_literal_expression_as__Bool(struct expression** new, struct yylloc* loc, struct type* bool_type, bool boollit);
#endif

int new_literal_expression_as_signed_char(struct expression** new, struct yylloc* loc, struct type*, signed char);

int new_literal_expression_as_unsigned_char(struct expression** new, struct yylloc* loc, struct type*, unsigned char);

int new_literal_expression_as_signed_short(struct expression** new, struct yylloc* loc, struct type*, signed short);

int new_literal_expression_as_unsigned_short(struct expression** new, struct yylloc* loc, struct type*, unsigned short);

int new_literal_expression_as_signed_int(struct expression** new, struct yylloc* loc, struct type*, signed int);

int new_literal_expression_as_unsigned_int(struct expression** new, struct yylloc* loc, struct type*, unsigned int);

int new_literal_expression_as_signed_long(struct expression** new, struct yylloc* loc, struct type*, signed long);

int new_literal_expression_as_unsigned_long(struct expression** new, struct yylloc* loc, struct type*, unsigned long);

int new_literal_expression_as_float(struct expression**, struct yylloc* loc, struct type*, float);

int new_literal_expression_as_double(struct expression**, struct yylloc* loc, struct type*, double);
