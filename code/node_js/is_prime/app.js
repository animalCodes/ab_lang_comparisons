const {argv, exit} = require("node:process");

// See fizzbuzz implementation for explanation of `Number` function etc.
// Attempt to retrieve input, check it's valid.
const num = Number(argv[2])
if (num == null) {
    console.log("No argument specified, exiting.")
    exit(1)
} else if (isNaN(num)) {
    console.log(`Couldn't convert ${argv[2]} to a number, exiting.`)
    exit(2)
}

// It should be noted that this implementation is overcomplicated by my wanting to
// use a recursive function.

// Verify number
if (num < 2) {
    console.log("False")
    exit(0)
}

// Check
if (isPrime(num)) console.log("True")
else console.log("False")

/**
 * Returns whether `num` is prime, by recursively checking each number lesser than it.
 */
function isPrime(num, divisor=num-1) {
    if (divisor <= 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    return isPrime(num, divisor-1)
}
