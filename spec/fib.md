# Fibonacci sequence

Computes and prints the *n*th fibonacci number.

In this specification, the first fibonacci number is 0 and the second is 1.

## Invocation

`fib n`

- `n` - Integer, which fibonacci number to print.

### Examples

| Input     | Output |
| --------- | ------ |
| `fib 0`   | `0`    |
| `fib 1`   | `1`    |
| `fib 3`   | `2`    |
| `fib 10`  | `55`   |
| `fib 4 6` | `3`    |
| `fib 7.5` | `13`   |
| `fib -10` | `-10`  |
| `fib foo` | `0`    |
| `fib`     | `0`    |

## Implementation

### Functions

- `atoi(str)` - Convert `str` to an integer, if it cannot be converted return `0`.

### Code

```
n = atoi(n)

if (n < 0)
    println("{n}")
    exit(0)
}

println("{fib(n)}")
```

> Ideally the computation should be implemented using a recursive function, as follows.

```
fib(n)
{
    if (n <= 1)
        return n
    return fib(n - 1) + fib(n - 2)
}
```

> However, if a language doesn't support recursive functions or a similar feature, a loop-based
> implementation may be used instead. Here is (a bad) one:

```
fib(n)
{
    f1 = 0
    f2 = 1
    t = 0

    while (--n > 0) {
        t = f2
        f2 = f1 + f2
        f1 = t
    }

    return f2
}
```

**Implemented in**: C, Python.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
