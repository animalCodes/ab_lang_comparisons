// Get 'first' argument
const input = Deno.args[0]
// Check argument exists, if not exit
if (input == null) {
    console.log("No input specified, exiting.")
    Deno.exit(1)
}

// Number() function will return `NaN` if unable to convert input to a number.
const num = Number(input)
if (isNaN(num)) {
    console.log(`Unable to convert "${input}" to a number, exiting.`)
    Deno.exit(2)
}

let output = ""
// Do fizzbuzzing
if (num % 3 == 0) output += "Fizz"
if (num % 5 == 0) output += "Buzz"
if (num == 0 || output == "") output = input; // ';' is unnecessary, I just find it a little bit easier to read.

// Throw output at user
console.log(output)
