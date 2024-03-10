# Number is prime

Prints "True" or "False" depending on whether the number received is a prime number.

## Implementation

The first argument given to the program (ignoring the path to the program itself) should be the number to check.
* If no input is received or it can't be converted to a number, notify user and exit.

While there are many ways to figure out if a number is prime, we'll stick to Trial Division, as it is reasonably efficient and can actually be understood by normal people.
If you are unfamiliar with the algorithm, I'd suggest reading the [Wikipedia article on Trial Division](https://en.wikipedia.org/wiki/Trial_division)

To figure out if the input is prime, we need to find out whether it has any factors. (apart from itself)

Firstly, there is a good chance that, if none-prime, the input will be divisible by 2 or 3. 
* Check that that the input is either not equal to 2 and divisible by 2, or not equal to 3 and divisible by 3.
* Print "False" if so.

If the above check didn't work, we need to check every possible factor of input.
We know the number can't be divisible by 2 or 3, so there is no point in checking whether it is divisible by 6, for instance. We need to skip those numbers.
* We can generate such a sequence by starting a counter at 5, incrementing it by 6, while additionally checking counter+2. This'll give us: 5 (7), 11 (13), 17 (19), 23 (25), 29 (31), 35 (37)..
* If any number in the sequence is a factor of input, print "False" and exit.

Additionally, we only need to check up to the square root of input, as anything above that will have already been checked - if the square root is 10, checking 25 (25 * 4 = 100) would be redundant, as we will have already checked 4. (Well, we don't check 4 due to it being a multiple of 2, but you get the point.)
* Stop generating the sequence if counter*counter is greater than or equal to the input.

* If all the above checks have passed without "False" being printed, print "True" and exit.

**Implemented in**: C, C++, C#, denoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.

**To be implemented in**:
