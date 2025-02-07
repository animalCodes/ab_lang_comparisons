# Simple wc

A simplified version of the `wc` GNU coreutil. Supporting the `-l`, `-w`, and `-c` options along with `-h`.

The primary purpose of this specification is to showcase simple command-line option parsing.

## Invocation

`swc [options] file`

- `options` - zero or more of `-l`, `-w`, `-c` or `-h` (may be grouped together). With the following results:
  - `l` - Print newline count.
  - `w` - Print word count. (a word is a sequence of non-whitespace delimited by whitespace or start/end of file)
  - `c` - Print byte count.
  - `h` - Override all other options and print help (see below).
  - If none are specified, treated as `-lwc`.

- `file` Path to file to read from, multiple may be specified, but only the first will be read.

### Examples

| Input                    | Output                                       |
| ------------------------ | -------------------------------------------- |
| `swc -l res/text.txt`    | `176`                                        |
| `swc -w res/text.txt`    | `1404`                                       |
| `swc -c res/text.txt`    | `8271`                                       |
| `swc -l -c res/text.txt` | `176 8271`                                   |
| `swc -lc res/text.txt`   | `176 8271`                                   |
| `swc -l -l res/text.txt` | `176`                                        |
| `swc res/text.txt`       | `176 1404 8271`                              |
| `swc -w -h res/text.txt` | help message (see below).                    |
| `swc -b res/text.txt`    | `Invalid option "b", try "swc -h" for help.` |
| `swc non_existent_file`  | `Cannot access file "non_existent_file"`     |
| `swc no_permission_file` | `Cannot access file "no_permission_file"`    |
| `swc`                    | `No file specified, exiting.`                |
| `swc -w`                 | `No file specified, exiting.`                |

## Implementation

### Functions

- `readable(path)` - Whether the file indicated by `path` exists and can be read.

- `append(arr, item)` - Append `item` to end of `array`.

- `isempty(arr)` - Whether `arr` is empty (has a length of zero).

- `lines(path)` - Number of newline characters (\n) in the file at `path`.

- `words(path)` - Number of words in the file at `path`.

- `bytes(path)` - Number of bytes in the file at `path`.

- `print_items(arr)` - Print each item in `arr`, separated by spaces. And a trailing newline.

### Code

> The help message is as follows

```
help_message = "Usage: swc [options] file\n
Print newline, word and byte counts for file. A word is a sequence of\n
non-whitespace delimited by whitespace or start/end of input.\n\n

The options below may be used to select which counts are printed, always in the\n
following order: newline, word, byte.\n
  -c  print byte count.\n
  -l  print newline count.\n
  -w  print word count.\n
  -h  display this help and exit."
```

> `options` is treated as an array of characters corresponding to the options
> which were specified. For instance, if the program was invoked as "swc -l -w
> (filename)", it will be ['l', 'w']. Duplicates are removed.

```
if (!isset(file)) {
    eprintln("No file specified, exiting.")
    exit(1)
}

if (!readable(file)) {
    eprintln("Cannot access file \"{file}\"")
    exit(1)
}

if (isempty(options)) {
    options = ['c', 'l', 'w']
}

output = []

for (option in options) {
    if (option == 'l') {
        append(output, lines(file))
    } else if (option == 'w') {
        append(output, words(file))
    } else if (option == 'c') {
        append(output, bytes(file))
    } else if (option == 'h') {
        print(help_message)
        exit(0)
    } else {
        println("Invalid option \"{option}\", try \"swc -h\" for help.")
        exit(1)
    }
}

print_items(output)
```

**Implemented in**: C.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Python, Ruby, Rust.
