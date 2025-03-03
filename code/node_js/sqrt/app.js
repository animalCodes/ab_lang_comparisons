const {argv, exit} = require("node:process");

// Node.js sqrt

square = NaN

if (argv.length >= 3)
    square = Number(argv[2])

if (square == 0) {
    console.log("0.00000")
    exit(0)
}

if (isNaN(square) || square < 0) {
    console.log("NaN")
    exit(0)
}

guess = 1

while (true) {
    prev = Math.floor(guess)
    guess = (guess + (square / guess)) / 2
    if (prev == Math.floor(guess))
        break
}

guess = (guess + (square / guess)) / 2
guess = (guess + (square / guess)) / 2

console.log(`${guess.toFixed(5)}`)
