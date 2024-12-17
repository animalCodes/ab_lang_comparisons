# Fibonacci sequence

Computes and prints the *n*th fibonacci number.

In this specification, the first fibonacci number is 0 and the second is 1.

## Invocation

`fib input`

- `input` - Integer, which fibonacci number to print.

### Examples

| Input                | Output              |
| -------------------- | ------------------- |
| `fib 0`              | `0`                 |
| `fib 1`              | `1`                 |
| `fib 3`              | `2`                 |
| `fib 10`             | `55`                |
| `fib 4 6`            | `3`                 |
| `fib 7.5`            | `13`                |
| `fib -10`            | `-10`               |
| `fib foo`            | `0`                 |
| `fib`                | `0`                 |

## Implementation

### Functions

- `atoi(str)` - Convert `str` to an integer, if it cannot be converted return `0`.

### Code

```
if (input == null) {
    n = 0
} else {
    n = atoi(input)
}

if (n < 0)
    println("{n}")
    exit(0)
}

n = fib(n)
```

> Ideally the computation should be implemented using a recursive function, as follows.

```
fib(n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

> However, if a language doesn't support recursive functions or a similar feature, a loop-based
> implementation may be used instead. Here is (a bad) one:

```
fib(n)
{
    int f1 = 0
    int f2 = 1
    int t = 0

    while (--n) {
        t = f2
        f2 = f1 + f2
        f1 = t
    }

    return f2
}
```

```
println("{n}")
```

**Implemented in**: C.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Python, Ruby, Rust.
