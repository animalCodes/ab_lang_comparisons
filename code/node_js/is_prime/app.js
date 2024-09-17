
// Node.js is_prime

const {argv, exit} = require("node:process");

if (argv[2] == null) {
    console.error("No number specified, exiting.")
    exit(1)
}

const num = Number(argv[2])
if (isNaN(num)) {
    console.error(`"${argv[2]}" cannot be converted into a number, exiting.`)
    exit(1)
}

if (!Number.isInteger(num)) {
    console.log("False")
    exit(0)
}

if (num < 2
    || num > 2 && num % 2 == 0
    || num > 3 && num % 3 == 0) {
    console.log("False")
    exit(0)
}

for (let i = 5; i*i < num; i += 6) {
    if (num % i == 0 || num % (i+2) == 0) {
        console.log("False")
        exit(0)
    }
}

console.log("True")
