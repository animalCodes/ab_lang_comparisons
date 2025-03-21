# FizzBuzz

Follow the rules of 'Fizzbuzz'.

For simplicity, this specification only implements the core functionality of the game.
That is, printing "Fizz", "Buzz", "FizzBuzz", or the number depending on input received, it does not count.

## Invocation

`fizzbuzz n`

- `n` - Number to check.

### Examples

| Input            | Output                                                |
| ---------------- | ----------------------------------------------------- |
| `fizzbuzz 1`     | `1`                                                   |
| `fizzbuzz 3`     | `Fizz`                                                |
| `fizzbuzz 3.0`   | `Fizz`                                                |
| `fizzbuzz 5`     | `Buzz`                                                |
| `fizzbuzz 5.3`   | `5.3`                                                 |
| `fizzbuzz 15`    | `FizzBuzz`                                            |
| `fizzbuzz lorem` | `"lorem" cannot be converted into a number, exiting.` |
| `fizzbuzz`       | `No number specified, exiting.`                       |

## Implementation

### Functions

- `num_str(str)` - Whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number,.

- `divisible(n, m)` - Whether `n` is cleanly divisible by `m`.

### Code

```
if (!isset(n)) {
    eprintln("No number specified, exiting.")
    exit(1)
}

if (!num_str(n)) {
    eprintln("\"{n}\" cannot be converted into a number, exiting.")
    exit(1)
}

n = str_to_num(n)

if (divisible(n, 3) && divisible(n, 5)) {
    println("FizzBuzz")
    exit(0)
}

if (divisible(n, 3))
    println("Fizz")
else if (divisible(n, 5))
    println("Buzz")
else
    println("{n}")
```

**Implemented in**: C, C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Python, Ruby, Rust.

**To be implemented in**:
