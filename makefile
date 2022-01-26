
CC = gcc

CFLAGS += -Werror -Wall
CFLAGS += -Wfatal-errors

CPPFLAGS += -D _GNU_SOURCE
CPPFLAGS += -I .
CPPFLAGS += -isystem ./extern

YACC = bison
YFLAGS += --warnings=error=all

LEX = flex

buildtype ?= release

ifeq ($(buildtype), release)
CPPFLAGS += -D RELEASE
CPPFLAGS += -D FORTIFY_SOURCE=2

CPPFLAGS += -D ENTER=
CPPFLAGS += -D HERE=
CPPFLAGS += -D EXIT=
CPPFLAGS += -D 'dpv(_)='
CPPFLAGS += -D 'dpvc(_)='
CPPFLAGS += -D 'dpvb(_)='
CPPFLAGS += -D 'dpvs(_)='
CPPFLAGS += -D 'dpvo(_)='
CPPFLAGS += -D 'dpvsn(_, __)='
CPPFLAGS += -D 'ddprintf(...)='
CPPFLAGS += -D TODO='assert(!"TODO")'
CPPFLAGS += -D CHECK='assert(!"CHECK")'

CFLAGS += -O2
CFLAGS += -flto
else ifeq ($(buildtype), testing)
CPPFLAGS += -D TESTING

CFLAGS += -include debug.h
CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable

else
CPPFLAGS += -D DEBUGGING

CFLAGS += -include debug.h
CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-value
CFLAGS += -Wno-maybe-uninitialized
endif

target ?= x64

ifeq ($(target), x64)
CPPFLAGS += -D X64_TARGET
else ifeq ($(target), iloc)
CPPFLAGS += -D ILOC_TARGET
endif

asm ?= quiet

ifeq ($(asm), quiet)
CPPFLAGS += -D QUIET_ASSEMBLY
else ifeq ($(asm), verbose)
CPPFLAGS += -D VERBOSE_ASSEMBLY
endif

on_error ?= do_nothing

ifeq ($(on_error), do_nothing)
ON_ERROR =
else ifeq ($(on_error), open_editor)
ON_ERROR += || ($$EDITOR $<; false)
else
$(error "invalid on_error option!");
endif

buildprefix = gen/$(buildtype)-build/target-$(target)/$(asm)-asm

default: $(buildprefix)/cminus

.PRECIOUS: %/
%/:
	@ mkdir -p $@

gen/srclist.mk: | gen/
	find -name '*.c' | sed 's/^/srcs += /' > $@

srcs += ./parser/scanner.c ./parser/parser.c

include gen/srclist.mk

#ARGS += -p ./test.cm
#ARGS +=    ./test.im
#ARGS +=    ./examples/system/helloworld.im
#ARGS += -p ./examples/system/helloworld.cm

#ARGS += ./examples/more/hard-stuff.cm
#ARGS += ./examples/more/struct-initializers.cm
#ARGS += -p ./examples/more/typecasts1.cm
#ARGS += examples/more/busy-printf.cm

#ARGS += ./examples/system/unistd.cm # has enums in it
#ARGS += ./examples/system/stdio.cm
#ARGS += ./examples/system/inttypes.cm

ARGS += -p ./examples/add.cm
#ARGS += -p ./examples/add.float.cm
#ARGS += -p ./examples/and.cm
#ARGS += ./examples/and.float.cm
#ARGS += -p ./examples/arith.cm
#ARGS += ./examples/arith2.cm
#ARGS += -p ./examples/array.cm
#ARGS += -p ./examples/array.float.cm
#ARGS += ./examples/bubble.cm
#ARGS += ./examples/bubble.float.cm
#ARGS += ./examples/call.cm
#ARGS += -p ./examples/constdim.cm # cannot cast from `signed int` to `signed int* const`!
#ARGS += -p ./examples/dcs.cm
#ARGS += -p ./examples/decl1.cm # use of undeclared variable 'C'!
#ARGS += -p ./examples/decl2.cm # variable 'b' redeclared in same scope with as different type!
#ARGS += -p ./examples/decl3.cm
#ARGS += -p ./examples/dim.cm
#ARGS += ./examples/dimen.cm
#ARGS += -p ./examples/div.cm
#ARGS += -p ./examples/div.float.cm
#ARGS += -p ./examples/dynamic.cm # valgrind errors: bug in source
#ARGS += -p ./examples/ecall.cm # cannot cast from `void` to `signed int`!
#ARGS += -p ./examples/ejohn1.cm
#ARGS += -p ./examples/ejohn2.cm
# ARGS += -p ./examples/eq.cm
#ARGS += ./examples/expr.cm
#ARGS += -p ./examples/expr.float.cm

# half way

#ARGS += ./examples/farray.cm
#ARGS += ./examples/func.cm
#ARGS += ./examples/func2.cm
#ARGS += ./examples/funcproc.cm
#ARGS += ./examples/func_no.cm
#ARGS += ./examples/f_noparams.cm
#ARGS += ./examples/gcd.cm
#ARGS += ./examples/gt.cm
#ARGS += ./examples/hello.cm
#ARGS += ./examples/if.cm
#ARGS += ./examples/if.float.cm
#ARGS += ./examples/if1.cm
#ARGS += ./examples/inv.cm
#ARGS += ./examples/io.cm
#ARGS += ./examples/io.float.cm
#ARGS += ./examples/log.cm
#ARGS += ./examples/lt.cm
#ARGS += ./examples/mul.cm
#ARGS += ./examples/mul.float.cm
#ARGS += ./examples/muldecl.cm
#ARGS += ./examples/newdyn.cm
#ARGS += ./examples/nodecl.cm
#ARGS += ./examples/nomeaning.cm
#ARGS += ./examples/not.cm
#ARGS += ./examples/or.cm
#ARGS += ./examples/or.float.cm
#ARGS += ./examples/param.cm
#ARGS += ./examples/proc2.cm
#ARGS += ./examples/procfunc.cm
#ARGS += ./examples/proc_no.cm
#ARGS += ./examples/p_noparams.cm
#ARGS += ./examples/qs.cm
#ARGS += ./examples/recurs.cm
#ARGS += ./examples/retn.cm
#ARGS += ./examples/simple.cm
#ARGS += ./examples/skeleton.cm
#ARGS += ./examples/sub.cm
#ARGS += ./examples/sub.float.cm
#ARGS += ./examples/swapper.cm
#ARGS += ./examples/sym.cm
#ARGS += ./examples/typ2.cm
#ARGS += ./examples/type1.cm
#ARGS += ./examples/var_multiple.cm
#ARGS += ./examples/var_multiple2.cm
#ARGS += ./examples/var_simple.cm
#ARGS += ./examples/while.cm
#ARGS += ./examples/while.float.cm
#ARGS += ./examples/while2.cm
#ARGS += ./examples/while2.float.cm
#ARGS += ./examples/while3.cm
#ARGS += ./examples/while_array.cm

ARGS += -o /tmp/test.s

rrun: $(buildprefix)/cminus
	$< ${ARGS}

valrun: $(buildprefix)/cminus
	valgrind -- $< ${ARGS}

valrun-stop: $(buildprefix)/cminus
	valgrind --gen-suppressions=yes -- $< ${ARGS}

valrun-leak: $(buildprefix)/cminus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -- $< ${ARGS}

$(buildprefix)/cminus: $(patsubst %.c,$(buildprefix)/%.o,$(srcs))
	@ echo "linking $@"
	@ $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(buildprefix)/%.o $(buildprefix)/%.d: %.c | $(buildprefix)/%/
	@ echo "compiling $<"
	@ $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -MD -o $(buildprefix)/$*.o $(ON_ERROR)

%.c %.h: %.y
	@ echo "$(buildprefix): yacc-ing $<"
	$(YACC) $(YFLAGS) --output=$*.c --defines=$*.h $< $(ON_ERROR)

%.c %.h: %.l
	@ echo "$(buildprefix): lex-ing $<"
	$(LEX) $(LFLAGS) --outfile=$*.c --header-file=$*.h $< $(ON_ERROR)

#%.im: %.cm
#	$(CPP) -x c $< -o $@

#test: $(buildprefix)/cminus
#	for f in $$(ls examples/*.cm | sort -V); \
#	do echo "testing '$$f'..."; $< $$f || exit 1; done

#valtest: $(buildprefix)/cminus
#	for f in $$(ls examples/*.cm | sort -V); \
#	do echo "testing '$$f'..."; valgrind --error-exitcode=42 -- $< $$f || exit 1; done

#full-test: $(buildprefix)/cminus
#	for f in $$(find examples -name '*.cm' | sort -V); \
#	do echo "testing '$$f'..."; $< $$f || exit 1; done

#full-valtest: $(buildprefix)/cminus
#	for f in $$(find examples -name '*.cm' | sort -V); \
#	do echo "testing '$$f'..."; valgrind --error-exitcode=42 -- $< $$f || exit 1; done

#CminusTypeChecker.tgz: \
#		.gitignore compile run *.c *.h makefile README.md \
#		avl/* cmdln/* defines/* enums/* examples/* expression/* macros/* \
#		memory/* misc/* parser/* scope/* statement/* type/* types/*
#	tar -cvzf $@ $^

clean:
	for l in $$(cat .gitignore); do rm -rvf $$l; done

ifneq "$(MAKECMDGOALS)" "clean"
include $(patsubst %.c,$(buildprefix)/%.d,$(srcs))
endif












