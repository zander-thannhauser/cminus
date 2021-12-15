
CC = gcc

CFLAGS += -Werror -Wall
CFLAGS += -Wfatal-errors

CPPFLAGS += -D _GNU_SOURCE
CPPFLAGS += -I .

buildtype = release

ifeq ($(buildtype), release)
CPPFLAGS += -D RELEASE
CPPFLAGS += -D FORTIFY_SOURCE=2

CFLAGS += -O2
CFLAGS += -flto
else ifeq ($(buildtype), testing)
CPPFLAGS += -D TESTING

CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable

else
CPPFLAGS += -D DEBUGGING

CFLAGS += -g
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-function
CFLAGS += -Wno-unused-but-set-variable
CFLAGS += -Wno-unused-value
CFLAGS += -Wno-maybe-uninitialized

#LDLIBS += -Wl,--wrap,fopen
#LDLIBS += -Wl,--wrap,fdopen
#LDLIBS += -Wl,--wrap,fclose
#LDLIBS += -Wl,--wrap,malloc
#LDLIBS += -Wl,--wrap,realloc
#LDLIBS += -Wl,--wrap,free
#LDLIBS += -Wl,--wrap,getline
#LDLIBS += -Wl,--wrap,open
#LDLIBS += -Wl,--wrap,openat
#LDLIBS += -Wl,--wrap,openat2
#LDLIBS += -Wl,--wrap,close
#LDLIBS += -Wl,--wrap,pipe2
#LDLIBS += -Wl,--wrap,creat

#LDLIBS += -lunwind
endif

YACC = bison
YFLAGS += --warnings=error=all

LEX = flex

default: gen/$(buildtype)/cminus

%.c %.h: %.y
	$(YACC) $(YFLAGS) --output=$*.c --defines=$*.h $< 

%.c %.h: %.l
	$(LEX) $(LFLAGS) --outfile=$*.c --header-file=$*.h $< 

.PRECIOUS: %/
%/:
	mkdir -p $@

gen/srclist.mk: | gen/
	find -name '*.c' | sed 's/^/srcs += /' > $@

srcs += ./parser/scanner.c ./parser/parser.c
include gen/srclist.mk

ARGS += ./test.cm
#ARGS += ./examples/system/helloworld.i

#ARGS += ./examples/add.cm
#ARGS += ./examples/add.float.cm
#ARGS += ./examples/and.cm
#ARGS += ./examples/and.float.cm
#ARGS += ./examples/arith.cm
#ARGS += ./examples/arith2.cm
#ARGS += ./examples/array.cm
#ARGS += ./examples/array.float.cm
#ARGS += ./examples/bubble.cm
#ARGS += ./examples/bubble.float.cm
#ARGS += ./examples/call.cm
#ARGS += ./examples/constdim.cm
#ARGS += ./examples/dcs.cm
#ARGS += ./examples/decl1.cm
#ARGS += ./examples/decl2.cm
#ARGS += ./examples/decl3.cm
#ARGS += ./examples/dim.cm
#ARGS += ./examples/dimen.cm
#ARGS += ./examples/div.cm
#ARGS += ./examples/div.float.cm
#ARGS += ./examples/dynamic.cm
#ARGS += ./examples/ecall.cm
#ARGS += ./examples/ejohn1.cm
#ARGS += ./examples/ejohn2.cm
#ARGS += ./examples/eq.cm
#ARGS += ./examples/expr.cm
#ARGS += ./examples/expr.float.cm
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

# not entirely working just yet:

#ARGS += ./examples/more/enums.cm
#ARGS += ./examples/more/old-functions.cm
#ARGS += ./examples/more/struct1.cm
#ARGS += ./examples/more/struct2.cm
#ARGS += ./examples/more/typ3.cm
#ARGS += ./examples/more/typecasts1.cm

#ARGS += ./examples/system/unistd.cm
#ARGS += ./examples/system/stdio.cm
#ARGS += ./examples/system/inttypes.cm

ARGS += -o ./test.s

rrun: gen/$(buildtype)/cminus
	$< ${ARGS}

valrun: gen/$(buildtype)/cminus
	valgrind -- $< ${ARGS}

valrun-stop: gen/$(buildtype)/cminus
	valgrind --gen-suppressions=yes -- $< ${ARGS}

valrun-leak: gen/$(buildtype)/cminus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -- $< ${ARGS}

gen/$(buildtype)/cminus: $(patsubst %.c,gen/$(buildtype)/%.o,$(srcs))
	$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@

gen/$(buildtype)/%.d: %.c | gen/$(buildtype)/%/
	$(CPP) $(CPPFLAGS) $< -MM -MT $@ -MF $@ || (gedit $<; false)

gen/$(buildtype)/%.o: %.c gen/$(buildtype)/%.d | gen/$(buildtype)/%/
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ || (gedit $<; false)

test: gen/$(buildtype)/cminus
	for f in $$(ls examples/*.cm | sort -V); \
	do echo "testing '$$f'..."; $< $$f || exit 1; done

valtest: gen/$(buildtype)/cminus
	for f in $$(ls examples/*.cm | sort -V); \
	do echo "testing '$$f'..."; valgrind --error-exitcode=42 -- $< $$f || exit 1; done

full-test: gen/$(buildtype)/cminus
	for f in $$(find examples -name '*.cm' | sort -V); \
	do echo "testing '$$f'..."; $< $$f || exit 1; done

full-valtest: gen/$(buildtype)/cminus
	for f in $$(find examples -name '*.cm' | sort -V); \
	do echo "testing '$$f'..."; valgrind --error-exitcode=42 -- $< $$f || exit 1; done

CminusTypeChecker.tgz: \
		.gitignore compile run *.c *.h makefile README.md \
		avl/* cmdln/* defines/* enums/* examples/* expression/* macros/* \
		memory/* misc/* parser/* scope/* statement/* type/* types/*
	tar -cvzf $@ $^

clean:
	for l in $$(cat .gitignore); do rm -rvf $$l; done

ifneq "$(MAKECMDGOALS)" "clean"
include $(patsubst %.c,gen/$(buildtype)/%.d,$(srcs))
endif












