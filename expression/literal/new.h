
#include <stdbool.h>
#include <stddef.h>

struct expression;
struct primitive_type;
struct type;

int new_literal_expression_as__Bool(struct expression** new, struct type* bool_type, bool boollit);

int new_literal_expression_as_signed_char(struct expression** new, struct type*, signed char);

int new_literal_expression_as_unsigned_char(struct expression** new, struct type*, unsigned char);

int new_literal_expression_as_signed_short(struct expression** new, struct type*, signed short);

int new_literal_expression_as_unsigned_short(struct expression** new, struct type*, unsigned short);

int new_literal_expression_as_signed_int(struct expression** new, struct type*, signed int);

int new_literal_expression_as_unsigned_int(struct expression** new, struct type*, unsigned int);

int new_literal_expression_as_signed_long(struct expression** new, struct type*, signed long);

int new_literal_expression_as_unsigned_long(struct expression** new, struct type*, unsigned long);

int new_literal_expression_as_float(struct expression**, struct type*, float);

int new_literal_expression_as_double(struct expression**, struct type*, double);
