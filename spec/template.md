# *Title*

*Short description of the program*

### Invocation

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

### Code

Pseudocode using a C-like structure in

```
fenced code blocks
```

outlining the operations an implementation should perform to fulfull the specification.

Specific restrictions:
- Variables and functions should be named in snake_case.
- Any linebreaks in printed output must be explicitly included. (\n)
- Blocks of code - i.e. after an if statement - must be wrapped in {}.
- To include a variable in a string, wrap that variable's name in `{}`s. For instance, `x = 1; print("{x}")` would print `1`.

and, if needed

> blockquotes

Containing higher-level explanations of *why* those operations are performed etc.

These should include anything that would otherwise be placed in a comment in the source code.

**Implemented in**: *Comma-separated list of languages this is currently implemented in*

**To be implemented in**: *Comma-separated list of languages that this currently **isn't** implemented in, but can and should be.*
