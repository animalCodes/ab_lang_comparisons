# Caesar C(i|y)pher

Also known as the "shift cipher", the caesar cipher works by shifting the letters of the message a certain number of positions up or down the alphabet.

As an example, the message "abc" encrypted with a shift (or *key*) of 3 would result in the message "def".

See [Caesar Cipher on Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher) for more.

## Implementation

### Functions

- `print_err(str)` - Send `str` to stderr with a trailing newline.

- `print(str)` - Send `str` to stdout with a trailing newline.

- `num_str(str)` - Whether `str` could be converted into a number.

- `str_to_num(str)` - Convert `str` into a number.

- `lowercase(str)` - Return a copy of `str` with all characters converted to lowercase.

- `size(str)` - The size (number of characters in) `str`.

- `shift(char, n)` - Return `char` shifted `n` times up or down the alphabet, "wrapping around" if necessary.

- `exit(code)` - Terminate program with exit code `code`.

### Code

> In the following pseudo-code, the first argument is the shift, all other arguments are treated as a single string accessible through the `message` variable.

```
if (argc < 3) {
    if (argc == 2)
        print_err("No message given, exiting.")
    else
        print_err("No shift or message given, exiting.")
    exit(1)
}

if (!num_str(argv[1])) {
    print_err("%s cannot be converted into a number, exiting.", argv[1])
    exit(1)
}

key = str_to_num(argv[1])

message = lowercase(message)

for (i = 0; i < size(message); i++) {
    message[i] = shift(message[i], key)
}

print(message)
```

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
