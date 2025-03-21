# Echo

Echo received arguments to stdout with a trailing newline.

## Invocation

`echo message`

- `message` - All arguments given to program, separated by spaces and treated as a single string.

### Examples

| Input                 | Output           |
| --------------------- | ---------------- |
| `echo Hello, World!`  | `Hello, World!`  |
| `echo --help`         | `--help`         |
| `echo Hello,\nWorld!` | `Hello,\nWorld!` |

## Implementation

### Code

```
println(message)
```

**Implemented in**: C, Node.js, Python.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Ruby, Rust.
