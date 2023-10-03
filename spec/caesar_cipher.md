# Caesar C(i|y)pher

One of the easiest ciphers to crack, nevertheless fun to implement.

Also known as the "shift cipher", the caesar cipher works by shifting the letters of the message a certain number of positions up or down the alphabet.

As an example, the message "abc" encrypted with a shift (or *key*) of 3 would result in the message "def".

See [Caesar Cipher on Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher).

## Implementation

* Should receive atleast two arguments when executed, the first being an integer representing the shift and the rest being the message to be encrypted.
  * Check for existence of message and shift, notify user and exit if not enough arguments are given.

* Convert the first argument to a number, this can be positive or negative.
  * If this cannot be done, notify the user and exit.

* For each letter of the message:
  * Check the letter is alphabetical, if not skip.
  * Shift the letter *x* times up or down the alphabet.

* Shifting:
  * Get the index of the letter in the alphabet. (for instance 'a' would be 0)
  * Add `shift` to the index.
  * If the shifted index is out of the bounds of the alphabet, it should "wrap around"
  * For instance, if the shift results in an index of -5, add 26 to it.
  * For positive invalid shifts, *subtract* 26.
  * The above two steps may need to be repeated for very large shifts.

* Print the scrambled message.

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
