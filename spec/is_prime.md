# Number is prime

Print "True" or "False" depending on whether the number received is a prime number.

(I always forget what a prime number is, so mainly as a note-to-self: A prime number is a number that can only be divided by 1 and itself with no remainder.)

**Showcases**: Checking remainders, recursion / loops.

* Receives input on execution via environment/command-line arguments.
    * If no input is received, notify user and exit.

* Convert input to a number
    * If unable to convert input to a number, notify user and exit.
    * If the number is less than 2, print "False" and exit early.

* For each number less than inputted number (excluding 0 and 1): 
    * Check remainder of number / lesser number (*divisor*)
    * If 0 (divisor is *a factor*) `number` isn't prime, print "False" and exit.

* If all lesser numbers are checked without exiting, print "True" and exit.

**Implemented in**: C#, denoJS, Go, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**: C, C++, Java.
