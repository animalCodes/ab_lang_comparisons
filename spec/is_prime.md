# Number is prime

Print "True" or "False" depending on whether the number received is a prime number.

While there are many ways to figure out if a number is prime, we'll stick to Trial Division, as it is reasonably efficient and can actually be understood by normal people.

**Showcases**: Remainders, recursion / loops, boolean operators.

* Receives input on execution via command-line argument.
    * If no input is received, notify user and exit.

* Convert input to a number
    * If unable to convert input to a number, notify user and exit.

* Preliminary check:
    * If `number` is less than 2, greater than two and divisible by two, or greater than 3 and divisible by 3. Print "False" and exit.
    * How exactly the above checks are run is up to the implementing developer.

* Example trial division steps:
    * Start a loop with a 'counter' variable that has an initial value of 5, increment by 6 on every iteration.
    * On every iteration, check whether `number` can be evenly divided by `counter` or `counter + 2`, if so, print "False" and exit.
    * Exit the loop once `counter` *is* or *is greater than* the square root of `number`.
    * If the loop is exited, every possible factor of `number` has been checked, print "True" and (if necessary) exit.

**Implemented in**: C, C++.

**To be implemented in**: C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
