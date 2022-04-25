
#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#include <assert.h>

#include <enums/error.h>

#include <type/print.h>

#include <expression/print.h>

#include "struct.h"
#include "vfprintf.h"

enum length_modifier {
	lm_char, lm_short, lm_int, lm_long, lm_long_long,
	lm_long_double, lm_intmax, lm_size, lm_ptrdiff};

int asm_writer_vfprintf(
	FILE* const stream,
	const char* fmt,
	va_list vargs)
{
	int error = 0;
	const char* end;
	enum length_modifier lm;
	struct { bool pound, zero, minus, space, plus; } flags;
	struct { bool is_set; unsigned int val; } field_width, digits_of_precision;
	ENTER;
	
	dpvs(fmt);
	
	for (end = fmt + strlen(fmt); !error && fmt < end; fmt++)
	{
		if (*fmt == '%')
		{
			for (fmt++,
				field_width.is_set = false,
				digits_of_precision.is_set = false,
				flags = (typeof(flags)) {},
				lm = lm_int;
				!error && fmt < end && index("#0- +", *fmt); fmt++)
			{
				switch (*fmt)
				{
					case '#': flags.pound = true; break;
					case '0': flags.zero  = true; break;
					case '-': flags.minus = true; break;
					case ' ': flags.space = true; break;
					case '+': flags.plus  = true; break;
				}
			}
			
			if (!error && fmt < end)
			{
				if (index("0123456789", *fmt))
				{
					field_width.is_set = true, field_width.val = 0;
					
					do field_width.val = field_width.val * 10 + *fmt++ - L'0';
					while (fmt < end && index("0123456789", *fmt));
				}
				else if (*fmt == '*')
				{
					fmt++;
					field_width.is_set = true,
					field_width.val = va_arg(vargs, int);
					
					dpv(field_width.val);
				}
			}
			
			if (!error && fmt < end && *fmt == '.')
			{
				if (fmt++, index("0123456789", *fmt))
				{
					digits_of_precision.is_set = true, digits_of_precision.val = 0;
					
					do digits_of_precision.val = digits_of_precision.val * 10 + *fmt++ - L'0';
					while (fmt < end && index("0123456789", *fmt));
				}
				else if (*fmt == '*')
				{
					fmt++;
					digits_of_precision.is_set = true,
					digits_of_precision.val = va_arg(vargs, int);
					
					dpv(digits_of_precision.val);
				}
			}
			
			if (!error && fmt < end)
			{
				switch (*fmt)
				{
					case 'h': fmt++, lm = (*fmt == 'h') ? (fmt++, lm_char) : lm_short; break;
					case 'l': fmt++, lm = (*fmt == 'l') ? (fmt++, lm_long_long) : lm_long; break;
					case 'q': fmt++, lm = lm_long_long; break;
					case 'L': fmt++, lm = lm_long_double; break;
					case 'j': fmt++, lm = lm_intmax; break;
					case 'z': fmt++, lm = lm_size; break;
					case 't': fmt++, lm = lm_ptrdiff; break;
				}
			}
			
			if (!error && fmt >= end)
				error = e_malformed_format_string;
			
			if (!error)
			{
				switch (*fmt)
				{
					case L'i':
					case L'd':
						// The int argument is converted to signed decimal
						// notation. The precision, if any, gives the minimum
						// number of digits that must appear; if the converted
						// value requires fewer digits, it is padded on the left
						// with zeros. The default precision is 1. When 0 is
						// printed with an explicit precision 0, the output is
						// empty.
					{
						intmax_t value;
						char format_string[100];
						
						sprintf(format_string,
							"%%%.*s%.*s%.*s%.*s%.*s*.*j%c",
							flags.pound, "#",
							flags.zero,  "0",
							flags.minus, "-",
							flags.space, " ",
							flags.plus,  "+",
							*fmt);
						
						dpvs(format_string);
						
						switch (lm)
						{
							case lm_char:      value = va_arg(vargs, unsigned       int); break;
							case lm_short:     value = va_arg(vargs, unsigned       int); break;
							case lm_int:       value = va_arg(vargs, unsigned       int); break;
							case lm_long:      value = va_arg(vargs, unsigned      long); break;
							case lm_long_long: value = va_arg(vargs, unsigned long long); break;
							case lm_ptrdiff:   value = va_arg(vargs,          ptrdiff_t); break;
							case lm_size:      value = va_arg(vargs,            ssize_t); break;
							case lm_intmax:    value = va_arg(vargs,           intmax_t); break;
							
							default: error = e_malformed_format_string; break;
						}
						
						dpv(value);
						
						fprintf(stream, format_string,
							field_width.is_set ? field_width.val : 0,
							digits_of_precision.is_set ? digits_of_precision.val : 1,
							value);
						
						break;
					}
					
					case L'o':
					case L'u':
					case L'x':
					case L'X':
						// The unsigned int argument is converted to unsigned
						// octal (o), unsigned decimal (u), or unsigned
						// hexadecimal (x and X) notation. The letters abcdef
						// are used for x conversions; the letters ABCDEF are
						// used for X conversions. The precision, if any, gives
						// the minimum  number of digits that must appear; if
						// the converted value requires fewer digits, it is
						// padded on the left with zeros. The default precision
						// is 1. When 0 is printed with an explicit precision 0,
						// the output is empty.
					{
						char digits[2 + 2 * 8 + 1];
						char* e = &digits[2 + 2 * 8 + 1], *m = e;
						uintmax_t val;
						unsigned base = *fmt == 'o' ? 8 : *fmt == 'u' ? 10 : 16;
						
						switch (lm)
						{
							case lm_char:      val = va_arg(vargs, signed       int); break;
							case lm_short:     val = va_arg(vargs, signed       int); break;
							case lm_int:       val = va_arg(vargs, signed       int); break;
							case lm_long:      val = va_arg(vargs, signed      long); break;
							case lm_long_long: val = va_arg(vargs, signed long long); break;
							
							case lm_intmax:  val = va_arg(vargs,   intmax_t); break;
							case lm_size:    val = va_arg(vargs,    ssize_t); break;
							case lm_ptrdiff: val = va_arg(vargs,  ptrdiff_t); break;
							
							default:
								val = 0;
								error = e_malformed_format_string;
								break;
						}
						
						if (!val)
							*--m = '0';
						else while (val) {
							*--m = "0123456789ABCDEF"[val % base];
							val /= base;
						}
						
						if (flags.pound)
						{
							*--m = 'x';
							*--m = '0';
						}
						
						size_t len = e - m;
						
						const char* const padding = flags.zero ? "0" : " ";
						if (field_width.is_set)
							while (field_width.val-- > len)
								if (fwrite(padding, 1, 1, stream) == EOF)
									return EOF;
						
						if (fwrite(m, 1, len, stream) < len)
							return EOF;
						
						break;
					}
					
					// above were all the integer converisions.
					
					case L'e':
					// case L'E':
						// The double argument is rounded and converted in the
						// style [-]d.ddde±dd where there is one digit before
						// the decimal-point character and the number of digits
						// after it is equal to the precision; if the precision
						// is missing, it is taken as 6; if the precision is
						// zero, no decimal-point character appears. An E
						// conversion uses the letter E (rather than e) to
						// introduce the exponent. The exponent always contains
						// at least two digits; if the value is zero, the
						// exponent is 00.
					case L'f':
					case L'F':
						// The double argument is rounded and converted to
						// decimal notation in the style [-]ddd.ddd, where the
						// number of digits after the decimal-point character is
						// equal to the precision specification. If the
						// precision is missing, it is taken as 6; if the
						// precision is explicitly zero, no decimal-point
						// character appears. If a decimal point appears, at
						// least one digit appears before it.
						
						// (SUSv2 does not know about F and says that character
						// string representations for infinity and NaN may be
						// made available. SUSv3 adds a specification for F. The
						// C99 standard specifies "[-]inf" or "[-]infinity" for
						// infinity, and a string starting with "nan" for NaN,
						// in the case of f conversion, and "[-]INF" or
						// "[-]INFINITY" or "NAN" in the case of F conversion.)
					case L'g':
					case L'G':
						// The double argument is converted in style f or e
						// (or F or E for G conversions). The precision
						// specifies the number of significant digits. If the
						// precision is missing, 6 digits are given; if the
						// precision is zero, it is treated as 1. Style e is
						// used if the exponent from its conversion is less
						// than -4 or greater than or equal to the precision.
						// Trailing zeros are removed from the fractional part
						// of the result; a decimal point appears only if it is
						// followed by at least one digit.
					case L'a':
					case L'A':
						// (C99; not in SUSv2, but added in SUSv3) For a
						// conversion, the double argument is converted to
						// hexadecimal notation (using the letters abcdef) in
						// the style [-]0xh.hhhhp±; for A conversion the prefix
						// 0X, the letters ABCDEF, and the exponent separator P
						// is used. There is one hexadecimal digit before the
						// decimal point, and the number of digits after it is
						// equal to the precision. The default precision
						// suffices for an exact representation of the value if
						// an exact representation in base 2 exists and
						// otherwise is sufficiently large to distinguish values
						// of type double. The digit before the decimal point is
						// unspecified for nonnormalized numbers, and nonzero
						// but otherwise unspecified for normalized numbers.
					{
						TODO;
						#if 0
						float128 value;
						char format_string[100], buffer[100];
						size_t len;
						
						verpv(field_width.set);
						verpv(digits_of_precision.set);
						
						verpv(flags.pound);
						verpv(flags.zero);
						verpv(flags.minus);
						verpv(flags.space);
						verpv(flags.plus);
						
						snprintf(format_string, 100,
							"%%%.*s%.*s%.*s%.*s%.*s*.*Q%c",
							flags.pound, "#",
							flags.zero,  "0",
							flags.minus, "-",
							flags.space, " ",
							flags.plus,  "+",
							*format);
						
						error = fetch_double(&value);
						
						verpv((double) value);
						
						if (!error)
							len = quadmath_snprintf(buffer, 100, format_string, 
								field_width.set ? field_width.val : 0,
								digits_of_precision.set ? digits_of_precision.val : 6,
								value);
						
						verpv(len);
						
						if (!error)
							error = push_string_as_wchar(output, print_to_array, buffer, len);
						#endif
						
						break;
					}
					
					case L'c':
						// If no l modifier is present, the int argument is
						// converted to an unsigned char, and the resulting
						// character is written. If an l modifier is present,
						// the wint_t (wide character) argument is converted to
						// a multibyte sequence by a call to the wcrtomb(3)
						// function, with a conversion state starting in the
						// initial state, and the resulting multibyte string
						// is written.
					{
						TODO;
						#if 0
						wchar_t value;
						
						error = fetch_character(&value);
						
						verpv(value);
						
						if (!error)
							error = array_push_n(output, &value);
						#endif
						
						break;
					}
					
					case L's':
						// If no l modifier is present: the const char *
						// argument is expected to be a pointer to an array of
						// character type (pointer to a string). Characters from
						// the array are written up to (but not including) a
						// terminating null byte ('\0'); if a precision is
						// specified, no more than the number specified are
						// written. If a precision is given, no null byte need
						// be present; if the precision is not specified, or
						// is greater than the size of the array, the array must
						// contain a terminating null byte.
						
						// If an l modifier is present: the const wchar_t *
						// argument is expected to be a pointer to an array of
						// wide characters. Wide characters from the array are
						// converted to multibyte characters (each by a call to
						// the wcrtomb(3) function, with a conversion state
						// starting in the initial state before the first wide
						// character), up to and including a terminating null
						// wide character. The resulting multibyte characters
						// are written up to (but not including) the terminating
						// null byte. If a precision is specified, no more bytes
						// than the number specified are written, but no partial
						// multibyte characters are written. Note that the
						// precision determines the number of bytes written, not
						// the number of wide characters or screen positions.
						// The array must contain a terminating null wide
						// character, unless a precision is given and it is so
						// small that the number of bytes written exceeds it
						// before the end of the array is reached.
					{
						fprintf(stream, "%*.*s", 
							field_width.is_set ? field_width.val : 0,
							digits_of_precision.is_set ? digits_of_precision.val : -1,
							va_arg(vargs, char*));
						
						break;
					}
					
					case L'p':
						// The void * pointer argument is printed in hexadecimal
						// (as if by %#x or %#lx).
					{
						TODO;
						#if 0
/*						const void* value;*/
/*						wchar_t format_string[100], buffer[100];*/
/*						size_t len;*/
						
						#if 0
						if (digits_of_precision < 0) digits_of_precision = 1;
						
						verpv(field_width);
						verpv(digits_of_precision);
						
						verpv(flags.pound);
						verpv(flags.zero);
						verpv(flags.minus);
						verpv(flags.space);
						verpv(flags.plus);
						
						swprintf(format_string, 100,
							L"%%%.*s%.*s%.*s%.*s%.*s*.*j%c",
							flags.pound, L"#",
							flags.zero,  L"0",
							flags.minus, L"-",
							flags.space, L" ",
							flags.plus,  L"+",
							*format);
						
						error = fetch_pointer(&value);
						
						verpv(value);
						
						if (!error)
							len = swprintf(buffer, 100, format_string, field_width, digits_of_precision, value);
						
						verpv(len);
						
						if (!error)
							error = array_mass_push_n(output, buffer, len);
						#endif
						TODO;
						#endif
						TODO;
						
						break;
					}
					
					case L'm':
						// (Glibc extension; supported by uClibc and musl.) 
						// Print output of strerror(errno). No argument is required.
					{
						TODO;
						#if 0
						wchar_t format_string[100], buffer[100];
						size_t len;
						
						verpv(field_width.set);
						verpv(digits_of_precision.set);
						
						verpv(flags.pound);
						verpv(flags.zero);
						verpv(flags.minus);
						verpv(flags.space);
						verpv(flags.plus);
						
						swprintf(format_string, 100,
							L"%%%.*s%.*s%.*s%.*s%.*s*.*j%c",
							flags.pound, L"#",
							flags.zero,  L"0",
							flags.minus, L"-",
							flags.space, L" ",
							flags.plus,  L"+",
							*format);
						
						len = swprintf(buffer, 100, format_string,
							field_width.set ? field_width.val : 0,
							digits_of_precision.set ? digits_of_precision.val : UINT_MAX);
						
						verpv(len);
						
						if (!error)
							error = array_mass_push_n(output, buffer, len);
						#endif
						
						break;
					}
					
					case L'%':
						// A '%' is written. No argument is converted.
					{
						putc('%', stream);
						break;
					}
					
					case 't':
					{
						struct type* type = va_arg(vargs, struct type*);
						type_print(type, NULL, stream);
						break;
					}
					
					case 'T':
					{
						char* name = va_arg(vargs, char*);
						struct type* type = va_arg(vargs, struct type*);
						type_print(type, name, stream);
						break;
					}
					
					case 'E':
					{
						struct expression* expression = va_arg(vargs, struct expression*);
						expression_print(expression, stream);
						break;
					}
					
					default:
						error = e_malformed_format_string;
						break;
				}
			}
		}
		else
		{
			putc(*fmt, stream);
		}
	}
	
	EXIT;
	return error;
}
