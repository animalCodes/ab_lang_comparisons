# Vigenère cipher

A cipher where each letter is enciphered using a caesar cipher whose shift is determined by the corresponding letter in the key.

The cipher was invented by Giovan Battista Bellaso in 1553. However, it was misattributed to Blaise de Vigenère, who published a different cipher in 1586. And the name has stuck.

See [Vigenère cipher on Wikipedia](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## Invocation

`vigenere_cipher message`
<br>
`key`

- `message` - The message to encipher.

- `key` - The key. Entered via stdin after program is executed.

### Examples

Second `input` text is key, as above.

| Input                                      | Output                                               |
| ------------------------------------------ | ---------------------------------------------------- |
| `vigenere_cipher abc` `a`                  | `abc`                                                |
| `vigenere_cipher abc` `bbbbb`              | `bcd`                                                |
| `vigenere_cipher cat` `dog`                | `foz`                                                |
| `vigenere_cipher attack at dawn` `victory` | `vbvtqb yo lcpb`                                     |
| `vigenere_cipher 22 pancakes` `hungry`     | `22 wuairilm`                                        |
| `vigenere_cipher abc` `one 2 three`        | `Key contains non-alphabetical characters, exiting.` |
| `vigenere_cipher` ``                       | `No message given, exiting.`                         |
| `vigenere_cipher abc` ``                   | `No key given, exiting.`                             |

## Implementation

### Functions

- `lowercase(str)` - Return a copy of `str` with all characters converted to lowercase.

- `readline(prompt)` - Print message `prompt` and return received input from stdin.

- `alphabetical(str)` - Whether `str` is comprised entirely of alphabetical (`[a-zA-Z]`) characters.

- `extend(str, n)` - Return `str` concatenated/truncated with itself until it has length `n`.

- `len(str)` - Length of `str`.

- `index(char)` - Zero-based index in the alphabet of character `c`. Returns `-1` for any non-alphabetical character.

- `alphabet(i)` - Character at zero-based index `i` in the alphabet. If `i` is greater than 25, wraps around. For instance, 26 is the same as 0.

### Code

```
if (!isset(message)) {
    eprintln("No message given, exiting.")
    exit(1)
}

key = readline("Enter key: ")

if (!isset(key)) {
    eprintln("No key given, exiting.")
    exit(1)
}

if (!alphabetical(key)) {
    eprintln("Key contains non-alphabetical characters, exiting.")
    exit(1)
}

message = lowercase(message)
key = lowercase(key)

key = extend(key, len(message))

for (i = 0; i < len(message)) {
    index = index(message[i])
    if (index != -1) {
        index += index(key[i])
        message[i] = alphabet(i)
        i += 1
    }
}

println(message)
```

**Implemented in**: C, Node.js, Python.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Ruby, Rust.
