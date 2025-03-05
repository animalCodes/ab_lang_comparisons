const {argv, exit} = require("node:process")

// Node.js fib

function fib(n) {
    if (n <= 1)
        return n
    return fib(n - 1) + fib(n - 2)
}

let n

if (argv.length >= 3)
    n = Math.floor(Number(argv[2]))
if (isNaN(n))
    n = 0

if (n < 0) {
    console.log(`${n}`)
    exit(1)
}

console.log(`${fib(n)}`)
