const {argv, exit} = require("node:process")

// The first argument (index 0) will usually be the path to node itself, such as
// "/usr/local/bin/node", and the second (1) will be the path to this file. After that come the arguments.

// the `Number()` *function* is generally more useful than the `Number` *constructor*.
// In short the function variant will return a primitive or NaN if unable to convert. 
// Whereas `new Number()` will always return a Number, which can be harder to work with.
const arg = Number(argv[2])

// This could also be `(arg == undefined)` because Javascript is weird.
if (arg == null) {
    console.error("No argument specified, exiting.")
    exit(1)
} else if (isNaN(arg)) {
    console.error(`Couldn't convert ${argv[2]} to a number, exiting.`)
    exit(2)
}

let string = "";
if (arg % 3 == 0) string += "Fizz"
if (arg % 5 == 0) string += "Buzz"

// Wrap arg in a template literal so that it's a string, otherwise `string` will become a number. 
// Which can sometimes be displayed differently in the console. this is entirely unnecessary but 
// I find it a bit cleaner.
if (string == "" || arg == 0) string = `${arg}`

console.log(string)
