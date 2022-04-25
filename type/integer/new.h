
struct integer_type;
enum integer_kind;

int new_integer_type(
	struct integer_type** new
	#ifdef X64_TARGET
	,enum integer_kind kind
	#endif
);
