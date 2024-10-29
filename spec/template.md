# *Title*

*Short description of the program*

## Invocation

`Title [arguments]`

- List of above arguments explaining how they should be interpreted and what they are used for.

Arguments may be referred to as variables in below pseudo-code, with `arg != null` meaning "argument was set" etc.

### Examples

A table showing example invocations and expected output, aim for at least 3.

Unless noted otherwise, output is implied to have a trailing newline.

| Input                | Output              |
| -------------------- | ------------------- |
| `{spec name} {args}` | `{expected output}` |

## Implementation

### Functions *(Optional)*

- List of functions used in the specification.

The following functions may be used in any specification without needing to be explicitly listed:

- `eprintln(str)` - Send `str` to stderr with a trailing newline.

- `println(str)` - Send `str` to stdout with a trailing newline.

- `exit(code)` - Terminate program with exit code `code`.

### Code

Pseudocode using a C-like structure in

```
fenced code blocks
```

outlining the operations an implementation should perform to fulfull the specification.

Specific restrictions:
- Variables and functions should be named in snake_case.
- Any linebreaks in printed output must be explicitly included. (\n)
- Statement blocks are delimited by {}.
- To include a variable in a string, wrap that variable's name in `{}`s. For instance, `x = 1; println("{x}")` would print `1`.
- Newlines and `;`s are valid statement terminators.
- Types need not be specified, except in function declarations.
- Lists/Arrays will grow or shrink automatically.
- Indentation is 4 spaces.
- Types with builtin methods aren't allowed, structs are.
- Strings may span multiple lines, linebreaks are implicitly stripped from them.

The following control flow constructs are available:
- `if` and `if/else` (Including `if/else if/else`)
- `while` and `do/while`
- `for (;;;)` and `for (x in y)`
- `switch`

Any default C operator may be used, additional ones may be used provided they are explained first.

It is implied that top-level statements are in a main() function or equivalent.

and, if needed

> blockquotes

Containing higher-level explanations of *why* those operations are performed etc.

These should include anything that would otherwise be placed in a comment in the source code.

**Implemented in**: *Comma-separated list of languages this is currently implemented in*

**To be implemented in**: *Comma-separated list of languages that this currently **isn't** implemented in, but can and should be.*
