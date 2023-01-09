const {argv, exit} = require("node:process");
// If this was an ES module (Most simply specified with a .mjs file extension) then the above would be written as:
// import {argv, exit} from "node:process";

// The first argument (index 0) will usually be the path to node itself, eg "/usr/local/bin/node", and the second (1) will be the path to this file. After that come the arguments.
// the Number() **function** is generally more useful than the actual Number constructor, in short the function variant will return a primitive or NaN if unable to convert. Whereas `new Number()` will always return a Number, which can be harder to work with.
const arg = Number(argv[2])
// This could also be `(arg == undefined)` because Javascript is weird.
if (arg == null) {
    console.log("No argument specified, exiting.")
    exit(1)
} else if (isNaN(arg)) {
    console.log(`Couldn't convert ${argv[2]} to a number, exiting.`)
    exit(2)
}

// I find it vaguely amusing how small a part the actual 'FizzBuzz' code is.
let string = "";
if (arg % 3 == 0) string += "Fizz"
if (arg % 5 == 0) string += "Buzz"

// Wrap arg in a template literal so that it's a string, otherwise `string` will become a number. Which can sometimes be displayed differently in the console. this is entirely unnecessary but I find it a bit cleaner.
if (string == "" || arg == 0) string = `${arg}`

console.log(string)
