# sqrt()

Print the square root of a given number accurate to 5 decimal places, or NaN if it cannot be computed.

This spec is largely based on the sqrt() function found in C's <math.h> header.

## Implementation

### Functions

- `print(str)` - Send `str` to stdout with a trailing newline.

- `print_n(num)` - Convert `num` to a string representing its value as a decimal number including 5 decimal places, send to stdout with a trailing newline.

- `nan(num)` - Whether `num` is NaN.

- `inf(num)` - Whether `num` is +Infinity.

- `floor(num)` Largest integer not greater than `num`.

- `exit(code)` - Terminate program with exit code `code`.

As the number - where possible - will be converted into a floating-point number, the following functions accept decimal number strings with an optional exponent indicating multiplication by a power of ten (scientific notation). Additionally, special values such as "inf", "infinity" and "nan" (with optional leading `+`/`-`, ignoring case) are accepted.

- `num_str(str)` - Test whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number.

### Code

```
if (argc < 2 || !num_str(argv[1])
    square = 0
else
    square = str_to_num(argv[1])

if (square == +0 || square == -0) {
    print(argv[1])
    exit(0)
} else if (nan(square) || square < -0) {
    print("NaN")
    exit(0)
} else if (inf(square)) {
    print("+Infinity")
    exit(0)
}
```

> We'll use [Heron's Method](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Heron's_method) to compute the square root, due to its relative simplicity and ease of implementation.
>
> TL:DR, Heron's method works by iteratively refining a guess until the desired precision is reached, we know the digits past a certain point are correct once they stop changing.
>
> While there are various methods of estimating a seed value, they end up being more complicated than the actual computation itself. So in the interest of simplicity, we'll use an initial estimate of 1.
>
> This specification uses a wonky method to ensure *all* integer digits are correct (check if previous and current values are the same once **floored**), please note that this is by no means *the* way to do it.
>
> Finally, Heron's method *roughly* doubles the precision of the guess on each iteration, so to be safe once the integer digits are correct, *6* further iterations are performed to ensure that at least 5 decimal digits are correct.

```
guess = 1

while (true) {
    prev = floor(guess)
    guess = (guess + (square / guess)) / 2
    if (prev == floor(guess))
        break
}

guess = (guess + (square / guess)) / 2;
guess = (guess + (square / guess)) / 2;
guess = (guess + (square / guess)) / 2;
guess = (guess + (square / guess)) / 2;
guess = (guess + (square / guess)) / 2;
guess = (guess + (square / guess)) / 2;

print_n(guess)
```

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
