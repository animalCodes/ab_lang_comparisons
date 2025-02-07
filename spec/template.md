# *Title*

*Short description of the program*

## Invocation

`Title [arguments]`

- List of above arguments explaining how they should be interpreted and what they are used for.

Arguments may be referred to as variables in below pseudo-code, with `arg == null` meaning "argument isn't set", etc.

### Examples

A table showing example invocations and expected output, aim for at least 3.

If the program doesn't have traditional input/output, (such as `http_hello_world`) a different table structure is allowed.

Unless noted otherwise, output is implied to have a trailing newline.

| Input                | Output              |
| -------------------- | ------------------- |
| `{spec name} {args}` | `{expected output}` |

## Implementation

### Functions *(Optional)*

List of functions used in the specification.

The following functions may be used in any specification without needing to be explicitly listed:

- `eprintln(str)` - Send `str` to stderr with a trailing newline.

- `println(str)` - Send `str` to stdout with a trailing newline.

- `isset(arg)` - Whether `arg` (given above) was supplied by the user.

- `exit(code)` - Terminate program with exit code `code`.

### Code

C-like pseudocode in

```
fenced code blocks
```

Outlining the operations an implementation should perform to fulfull the specification.

Pseudo-code should be kept as high-level as possible, only barely outlining what needs to be done - not *how*.
In cases where specific techniques need to be shown, use C-like syntax.

Specific restrictions:
- Statement blocks are delimited by {}.
- Newlines and `;`s are valid statement terminators. Do not end lines with `;`s.
- Types should **not** be specified.
- Variables and functions should be named in snake_case.
- Indentation should be kept to 4 spaces.
- To include an expression in a string, wrap it in `{}`s. For instance, `x = 1; println("{x}")` would print `1`.
- Strings may span multiple lines, linebreaks are implicitly stripped from them.

Lastly, use other specifications as your main reference rather than this document.

and, if needed

> blockquotes

Containing higher-level explanations of *why* those operations are performed etc.

These should include anything that would otherwise be placed in a comment in the source code.

**Implemented in**: *Comma-separated list of languages this is currently implemented in*

**To be implemented in**: *Comma-separated list of languages that this currently **isn't** implemented in, but can and should be.*
