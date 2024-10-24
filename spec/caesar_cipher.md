# Caesar C(i|y)pher

Also known as the "shift cipher", the caesar cipher works by shifting the letters of the message a certain number of positions up or down the alphabet.

As an example, the message "abc" encrypted with a shift (or *key*) of 3 would result in the message "def".

See [Caesar Cipher on Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher) for more.

## Invocation

`caesar_cipher shift message`

- `shift` - The number of places to shift each character of `message`, may be negative.

- `message` - The message to shift, rest of arguments given to program treated as a single string.

### Examples

| Input                  | Output                                           |
| ---------------------  | ------------------------------------------------ |
| `caesar_cipher 3 abc`  | `def`                                            |
| `caesar_cipher -3 abc` | `xyz`                                            |
| `caesar_cipher 65 abc` | `nop`                                            |
| `caesar_cipher 0 abc`  | `abc`                                            |
| `caesar_cipher 5 foo1` | `ktt1`                                           |
| `caesar_cipher foo a`  | `Couldn't convert "foo" to an integer, exiting.` |
| `caesar_cipher 5`      | `No message given, exiting.`                     |
| `caesar_cipher`        | `No shift or message given, exiting.`            |

## Implementation

### Functions

- `int_str(str)` - Whether `str` could be converted into an integer.

- `str_to_int(str)` - Convert `str` into an integer.

- `lowercase(str)` - Return a copy of `str` with all characters converted to lowercase.

- `size(str)` - The size (number of characters in) `str`.

- `shift(char, n)` - Return `char` shifted `n` times up or down the alphabet, "wrapping around" if necessary. None-alphabetical characters are left as-is.

### Code

```
if (shift == null || message == null) {
    if (shift != null) {
        eprintln("No message given, exiting.")
    else
        eprintln("No shift or message given, exiting.")
    exit(1)
}

if (!int_str(shift)) {
    eprintln("Couldn't convert \"{shift}\" to an integer, exiting.")
    exit(1)
}

key = str_to_int(shift)

message = lowercase(message)

for (i = 0; i < size(message); i++) {
    message[i] = shift(message[i], key)
}

println(message)
```

**Implemented in**: C, C#, Java.

**To be implemented in**: C++, denoJS, Go, Kotlin, Node.js, Ruby, Rust.
