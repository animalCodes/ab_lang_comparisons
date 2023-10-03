# FizzBuzz

Emulate the game 'Fizzbuzz' the rules of which are essentially: 

* Count up from 1, 
    * if the number is divisible by 3, say "Fizz",
    * if the number is divisible by 5, say "Buzz", 
    * If the number is divisible by 3 *and* 5, say "FizzBuzz",
    * Otherwise, print the number.

For simplicity, this specification only implements the core functionality of the game, that is printing "Fizz", "Buzz", "FizzBuzz", or the number depending on input received, it does not count.

## Implementation

*Note*: The below steps are just a guide for what operations should be performed, how exactly this program is implemented is up to the developer - as long as it works, is readable, and is reasonably efficient, it's valid!

* Receives input on execution
    * If no input is received, notify user and terminate program.

* If needed, convert input to a number (developer chooses what type of number is most appropriate)
    * If input cannot be converted to a number for whatever reason, notify user and terminate program.

* If the number is divisible by 3, print "Fizz"

* If the number is divisible by 5, print "Buzz"

* If the number is divisible by 3 AND 5, print "FizzBuzz"

* Otherwise, print the number.

**Implemented in**: C, C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**: 
