
#ifdef X64_TARGET
#ifndef ENUM_REGISTER_SIZE
#define ENUM_REGISTER_SIZE

enum register_size
{
	byte,
	word,
	doubleword,
	quadword,
	
	number_of_register_sizes,
};

#endif
#endif
