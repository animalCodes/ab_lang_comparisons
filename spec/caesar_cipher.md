# Caesar C(i|y)pher

One of the easiest ciphers to crack, nevertheless fun to implement.

Also known as the "shift cipher", the caesar cipher works by shifting the letters of the message a certain number of positions up or down the alphabet.

As an example, the message "abc" encrypted with a shift (or *key*) of 3 would result in the message "def".

See [Caesar Cipher on Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher).

## Implementation

Should receive at least two arguments when executed, the first being an integer representing the shift and the rest being the message to be encrypted.
* Notify user and exit if not enough arguments are given.

Convert the first argument to a number - the key, this can be positive or negative.
* If this cannot be done, notify the user and exit.

Ensure every character in the message is lowercase.

For every character in the message, if it's alphabetical:
* If the key is positive, shift it that many times "up" the alphabet.
* If the key is negative, shift it that many times "down" the alphabet.
* In the case of "overflows", wrap around to the other end of the alphabet and continue shifting.

Print the scrambled message.

**Implemented in**: C.

**To be implemented in**: C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
