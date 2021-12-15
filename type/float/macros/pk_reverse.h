
#define pk_reverse(type) \
	(_Generic(type, \
		signed char:    pk_signed_char, \
		unsigned char:  "%*s" #val " == " "(unsigned char) %hhu\n", \
		signed short:   "%*s" #val " == " "(signed short) %hi\n", \
		unsigned short: "%*s" #val " == " "(unsigned short) %hu\n", \
		signed int:     "%*s" #val " == " "(signed int) %i\n", \
		unsigned int:   "%*s" #val " == " "(unsigned int) %u\n", \
		signed long:    "%*s" #val " == " "(signed long) %li\n", \
		unsigned long:  "%*s" #val " == " "(unsigned long) %lu\n", \
		float:          "%*s" #val " == " "(float) %f\n", \
		double:         "%*s" #val " == " "(double) %lf\n", \
		default:        "%*s" #val " == " "(void*) %p\n"))
