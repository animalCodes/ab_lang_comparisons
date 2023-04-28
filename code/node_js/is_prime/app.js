const {argv, exit} = require("node:process");

// See fizzbuzz implementation for explanation of `Number` function etc.
// Attempt to retrieve input, check that it is valid.
const num = Number(argv[2])
if (num == null) {
    console.log("No argument specified, exiting.")
    exit(1)
} else if (isNaN(num)) {
    console.log(`Couldn't convert ${argv[2]} to a number, exiting.`)
    exit(2)
}

// Verify `num`
if (num < 2 
    || num > 2 && num % 2 == 0 
    || num > 3 && num % 3 == 0) {
    console.log("False")
    exit(0)
}

// Check
for (let i = 5; i*i < num; i += 6) {
    if (num % i == 0 || num % (i+2) == 0) {
        console.log("False")
        exit(0)
    }
}

console.log("True")
