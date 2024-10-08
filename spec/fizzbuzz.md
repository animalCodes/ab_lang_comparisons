# FizzBuzz

Follow the rules of 'Fizzbuzz'.

For simplicity, this specification only implements the core functionality of the game. That is, printing "Fizz", "Buzz", "FizzBuzz", or the number depending on input received, it does not count.

### Invocation

`fizzbuzz num`

- `num` - Number to check.

### Examples

| Input            | Output                                                |
| ---------------- | ----------------------------------------------------- |
| `fizzbuzz 1`     | `1`                                                   |
| `fizzbuzz 3`     | `Fizz`                                                |
| `fizzbuzz 3.0`   | `Fizz`                                                |
| `fizzbuzz 5`     | `Buzz`                                                |
| `fizzbuzz 5.3`   | `5.3`                                                 |
| `fizzbuzz 15`    | `FizzBuzz`                                            |
| `fizzbuzz`       | `No number specified, exiting.`                       |
| `fizzbuzz lorem` | `"lorem" cannot be converted into a number, exiting.` |

## Implementation

### Functions

- `print_err(str)` - Send `str` to stderr with a trailing newline.

- `print(str)` - Send `str` to stdout with a trailing newline.

- `num_str(str)` - Whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number,.

- `divisible(n, m)` - Whether `n` is cleanly divisible by `m`.

- `exit(code)` - Terminate program with exit code `code`.

### Code

```
if (num == null) {
    print_err("No number specified, exiting.")
    exit(1)
}

if (!num_str(num)) {
    print_err("\"{num}\" cannot be converted into a number, exiting.")
    exit(1)
}

n = str_to_num(num)

if (divisible(n, 3) && divisible(n, 5)) {
    print("FizzBuzz")
    exit(0)
}

if (divisible(n, 3))
    print("Fizz")
else if (divisible(n, 5))
    print("Buzz\n")
else
    print("{num}")
```

**Implemented in**: C, C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**:
