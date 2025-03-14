# Quine

A program taking no input and producing it's own source code as output.

In this case, "output" is just printing to stdout.

## Invocation

`quine`

### Examples

| Input                           | Output                                            |
| ------------------------------- | ------------------------------------------------- |
| `quine \| diff - {source file}` | (No output, inputs are identical)                 |

<!-- Plaintext readers: The above '\' is used to escape the '|' and should *not* be used in the commandline. -->

## Implementation

### Code

Providing example pseudo-code doesn't make sense, as the output of a given
implementation will depend on it's source.

The only requirement for an implementation of this specification is that
it's output matches it's source code. This can be easily checked with the
commandline provided in the *Examples* section.

Good luck!

**Implemented in**: C, Node.js, Python.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
