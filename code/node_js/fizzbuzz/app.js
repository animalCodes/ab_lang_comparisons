const {argv, exit} = require("node:process")

const arg = Number(argv[2])

// This could also be `(arg == undefined)` because Javascript is weird.
if (arg == null) {
    console.error("No number specified, exiting.")
    exit(1)
} else if (isNaN(arg)) {
    console.error(`${argv[2]} cannot be converted into a number, exiting.`)
    exit(1)
}

let string = "";
if (arg % 3 == 0) string += "Fizz"
if (arg % 5 == 0) string += "Buzz"

// Wrap arg in a template literal so that it's a string, otherwise `string`
// will become a number.  Which can sometimes be displayed differently in the
// terminal. this is entirely unnecessary but I find it a bit cleaner.
if (string == "" || arg == 0) string = `${arg}`

console.log(string)
