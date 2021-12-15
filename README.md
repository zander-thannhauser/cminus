
Basic stuff:
```
$ sudo apt install bash coreutils findutils
```

Install Bison and Flex with the command:
```
$ sudo apt install bison flex m4
```

I'm not certain if `gcc` and `make` are installed by default, so just in case:
```
$ sudo apt install binutils gcc make
```
For AST output:
```
$ sudo apt install graphviz
```

I have #defined many macros in `debug.h`, to aid in development but are unused
in the release-build of the program. It prints when functions get called, values
of variables, memory leaks, etc. Debugging requires libunwind to have stacetraces,
so when debugging, you need to install libunwind development files:
```
$ sudo apt install libunwind-dev
```
