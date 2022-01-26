
#ifdef X64_TARGET

#include "floatregs.h"

const char* floatregs[number_of_float_registers] =
{
	[  first_fparameter] = "%xmm0",
	[ second_fparameter] = "%xmm1",
	[  third_fparameter] = "%xmm2",
	[ fourth_fparameter] = "%xmm3",
	[  fifth_fparameter] = "%xmm4",
	[  sixth_fparameter] = "%xmm5",
	[seventh_fparameter] = "%xmm6",
	[ eighth_fparameter] = "%xmm7",
	
	[working_f1] = "%xmm8",
	[working_f2] = "%xmm9",
	[working_f3] = "%xmm10",
	[working_f4] = "%xmm11",
	[working_f5] = "%xmm12",
	[working_f6] = "%xmm13",
	[working_f7] = "%xmm14",
	[working_f8] = "%xmm15",
	
};

#endif
