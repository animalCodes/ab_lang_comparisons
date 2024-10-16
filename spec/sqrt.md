# sqrt()

Print the square root of a given number accurate to 5 decimal places, or NaN if it cannot be computed.

This spec is largely based on the sqrt() function found in C's <math.h> header.

### Invocation

`sqrt in`

- `in` - Number to calculate square root of, in format described in Functions section.

### Examples

| Input      | Output     |
| ---------- | ---------- |
| `sqrt 0`   | `0.00000`  |
| `sqrt 25`  | `5.00000`  |
| `sqrt 73`  | `8.54400`  |
| `sqrt 1e2` | `10.00000` |
| `sqrt -10` | `NaN`      |
| `sqrt nan` | `NaN`      |
| `sqrt foo` | `NaN`      |
| `sqrt`     | `NaN`      |

## Implementation

### Functions

- `print_n(num)` - Convert `num` to a string representing its value as a decimal number including 5 decimal places, send to stdout with a trailing newline.

- `floor(num)` Largest integer not greater than `num`.

- `exit(code)` - Terminate program with exit code `code`.

The following functions accept decimal number strings with an optional exponent indicating multiplication by a power of ten ("E" notation).

- `num_str(str)` - Test whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number.

### Code

```
if (in == null || !num_str(in))
    square = NaN
else
    square = str_to_num(in)

if (square == 0) {
    println("{square}")
    exit(0)
}

if (square == NaN || square < 0) {
    println("NaN")
    exit(0)
}
```

> We'll use [Heron's Method](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Heron's_method) to compute the square root, due to its relative simplicity and ease of implementation.
>
> TL:DR, Heron's method works by iteratively refining a guess until the desired precision is reached, we know the digits past a certain point are correct once they stop changing.
>
> While there are various methods of estimating a seed value, they end up being more complicated than the actual computation itself. So in the interest of simplicity, we'll use an initial estimate of 1.
>
> The below method of computing the integer part iterates once more than strictly necessary, as Heron's Method *roughly* doubles the number of correct digits per iteration, we only need to iterate *twice* more to compute the 5 decimal digits.

```
guess = 1

while (true) {
    prev = floor(guess)
    guess = (guess + (square / guess)) / 2
    if (prev == floor(guess))
        break
}

guess = (guess + (square / guess)) / 2
guess = (guess + (square / guess)) / 2

print_n(guess)
```

**Implemented in**: C, Java.

**To be implemented in**: C++, C#, denoJS, Go, Kotlin, Node.js, Ruby, Rust.
