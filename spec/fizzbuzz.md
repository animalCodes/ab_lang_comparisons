# FizzBuzz

Follow the rules of 'Fizzbuzz'.

For simplicity, this specification only implements the core functionality of the game. That is, printing "Fizz", "Buzz", "FizzBuzz", or the number depending on input received, it does not count.

## Implementation

### Functions

- `print_err(str)` - Send `str` to stderr with a trailing newline.

- `print(str)` - Send `str` to stdout with a trailing newline.

- `num_str(str)` - Test whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number.

- `exit(code)` - Terminate program with exit code `code`.

### Code

```
if (argc < 2) {
    print_err("No number specified, exiting.")
    exit(1)
}

if (num_str(argv[1])) {
    print_err("%s cannot be converted into a number, exiting.", argv[1])
    exit(1)
}

n = str_to_num(argv[1])

if (n divisible by 3 && n divisible by 5) {
    print("FizzBuzz")
    exit(0)
}

if (n divisible by 3) {
    print("Fizz")
}
else if (n divisible by 5) {
    print("Buzz\n")
}
else {
    print(argv[1])
}
```

**Implemented in**: C, C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**:
