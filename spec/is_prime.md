# Number is prime

Prints "True" or "False" depending on whether the number received is a prime number.

### Invocation

`is_prime in`

- `in` - Number to check.

### Examples

| Input            | Output                                                |
| ---------------- | ----------------------------------------------------- |
| `is_prime -1`    | `False`                                               |
| `is_prime 0`     | `False`                                               |
| `is_prime 2`     | `True`                                                |
| `is_prime 5.6`   | `False`                                               |
| `is_prime 13`    | `True`                                                |
| `is_prime 25`    | `False`                                               |
| `is_prime`       | `No number specified, exiting.`                       |
| `is_prime lorem` | `"lorem" cannot be converted into a number, exiting.` |

## Implementation

### Functions

- `num_str(str)` - Whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number.

- `natural(n)` - Whether `n` is a natural number (positive integer).

- `divisible(n, m)` - Whether `n` is divisible by `m` (remainder of 0).

### Code

```
if (in == null) {
    eprintln("No number specified, exiting.")
    exit(1)
}

if (num_str(in)) {
    eprintln("\"{in}\" cannot be converted into a number, exiting.")
    exit(1)
}

n = str_to_num(in)

if (!natural(n)) {
    println("False")
    exit(0)
}
```

> While there are many ways to figure out if a number is prime, we'll stick to Trial Division, as it is reasonably efficient and can actually be understood by normal people.
>
> If you are unfamiliar with the algorithm, I'd suggest reading the [Wikipedia article on Trial Division](https://en.wikipedia.org/wiki/Trial_division)

> Before resorting to that, however, some numbers can be easily eliminated.
>
> Firstly, there are no prime numbers less than 2.
>
> Secondly, there is a good chance that, if none-prime, the input will be divisible by 2 or 3. 

```
if (n < 2 || (n > 2 && divisible(n, 2)) || (n > 3 && divisible(n, 3))) {
    println("False")
    exit(0)
}
```

> If the above checks passed, we need to check every possible factor of `n`.
>
> We know the number can't be divisible by 2 or 3, so there is no point in checking whether it is divisible by 6, for instance. We need to skip those numbers.
>
> Additionally, we only need to check up to the square root of `n`, as anything above that will have already been checked - if the square root is 10, checking 25 (25 * 4 = 100) would be redundant, as we will have already checked 4.
>
> This is actually quite simple, like so:

```
for (i = 5; i*i <= n; i += 6) {
    if (divisible(n, i) || divisible(n, i+2)) {
        println("False")
        exit(0)
    }
}

println("True")
```

**Implemented in**: C, C++, C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**:
