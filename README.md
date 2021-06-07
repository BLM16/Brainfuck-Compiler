Brainfuck Compiler
==================
[![C++](https://img.shields.io/static/v1?label=C%2B%2B&message=v17&color=purple&link=https://docs.microsoft.com/en-us/cpp/?view=msvc-160)](https://docs.microsoft.com/en-us/cpp/?view=msvc-160) [![License](https://img.shields.io/badge/license-MIT-blue.svg?label=License&link=https://mit-license.org/)](./LICENSE)

Brainfuck compiler converts a brainfuck file into equivalent c code and compiles it into an executable.

## Syntax

* The compiler will only compile files that have the extension `.b` or `.bf`
* The compiler ignores all characters in the source file except `[]<>+-,.`

## Options

| Option (* are required) | Flag | Description                                         |
| ----------------------- | ---- | --------------------------------------------------- |
| *Input File             |      | Specify the source file to compile: `inputfile.bf`. |
| *Output File            | -o   | Specify the output file: `-o outfile.exe`.          |
| Compile to C            | -c   | Compile the source to c code, not an an executable. |

\
Compile `in.bf` into an executable `out.exe`.
```
bfcompiler in.bf -o out.exe
```

Compile `in.bf` into `out.c` as c code.
```
bfcompiler in.bf -c -o out.c
```

## License
This code is licensed under the [MIT License](./LICENSE).
