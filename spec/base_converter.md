# Base Converter

Convert given decimal integer into binary, octal or hexadecimal.

### Invocation

`base_converter base number`

- `base` - The base to convert `number` into, one of `2`, `8` or `16`.

- `number` - The number to convert - a decimal integer.

### Examples

| Input                   | Output                                    |
| ----------------------  | ----------------------------------------- |
| `base_converter 2 4`    | `100`                                     |
| `base_converter 8 10`   | `12`                                      |
| `base_converter 16 255` | `FF`                                      |
| `base_converter 2 0`    | `0`                                       |
| `base_converter 5 ten`  | `"ten" isn't a decimal integer, exiting.` |
| `base_converter 16`     | `No number specified, exiting.`           |
| `base_converter 20 1`   | `Base must be 2, 8 or 16, exiting.`       |
| `base_converter two 54` | `Base must be 2, 8 or 16, exiting.`       |
| `base_converter`        | `No base or number specified, exiting.`   |

## Implementation

### Functions

- `print_err(str)` - Send `str` to stderr with a trailing newline.

- `print(str)` - Send `str` to stdout with a trailing newline.

- `num_str(str)` - Whether `str` could be converted into a decimal integer.

- `binary(str)` - The decimal value of `str` converted to (simple, not two's complement) binary.

- `octal(str)` - The decimal value of `str` converted to octal.

- `hexadecimal(str)` - The decimal value of `str` converted to hexadecimal.

- `exit(code)` - Terminate program with exit code `code`.

### Code

```
if (number == null) {
    print_err("No number specified, exiting.")
    exit(1)
}

if (number == null && base == null) {
    print_err("No base or number specified, exiting.")
    exit(1)
}

if (!num_str(number)) {
    print_err("\"{number}\" isn't a decimal integer, exiting.")
    exit(1)
}

if (base == "2")
    print(binary(number))
else if (base == "8") {
    print(octal(number))
else if (base == "16")
    print(hexadecimal(number))
else {
    print_err("Base must be 2, 8, or 16, exiting.")
    exit(1)
}
```

**Implemented in**:

**To be implemented in**: C, C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
