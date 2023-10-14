// Deno throws away the path to the script, spicy!
const input = Deno.args[0]

if (input == null) {
    console.error("No input specified, exiting.")
    Deno.exit(1)
}

// Number() function will return `NaN` if unable to convert input to a number.
const num = Number(input)
if (isNaN(num)) {
    console.error(`Unable to convert "${input}" to a number, exiting.`)
    Deno.exit(2)
}

let output = ""
if (num % 3 == 0) output += "Fizz"
if (num % 5 == 0) output += "Buzz"
if (num == 0 || output == "") output = input

console.log(output)
