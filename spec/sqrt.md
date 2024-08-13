# sqrt()

Print the square root of a given number accurate to 5 decimal places, or NaN if it cannot be computed.

## Implementation

This spec is largely based on the sqrt() function found in C's "libm".

The first argument given to the program should be a decimal number string with an optional exponent indicating multiplication by a power of ten (scientific notation).
As the argument will be converted into a floating-point number, the special values "inf", "infinity" and "nan" (with optional leading +/-, ignoring case) should be parsed as such.
* If input is none-existent or cannot be converted into a (double precision) float, treat as 0.

If the parsed input is:
* +0 or -0, print input and exit.
* NaN or < -0, print "NaN" and exit.
* +Infinity, print "+Infinity" and exit.

From here on, the parsed input will be referred to as `square`.

We'll use [Heron's Method](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Heron's_method) to compute the square root, due to it's relative simplicity and ease of implementation.

TL:DR, Heron's method works by iteratively refining a guess until the desired precision is reached, we know the digits past a certain point are correct once they stop changing.

While there are various methods of estimating a seed value, they end up being more complicated than the actual computation itself. So in the interest of simplicity, we'll use an initial estimate of 1.
* initialise `guess` to 1.

Compute the following until the integer part + the first 5 decimal digits of `guess` are correct (unchanging):
* `guess` = (`guess` + (`square` / `guess`))

Print the computed square root including its first 5 decimal digits.

**Implemented in**:

**To be implemented in**: C, C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
