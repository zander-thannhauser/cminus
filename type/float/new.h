
struct float_type;
enum float_kind;

int new_float_type(
	struct float_type** new
	#ifdef X64_TARGET
	, enum float_kind kind
	#endif
);
