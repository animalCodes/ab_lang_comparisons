
// DenoJS fizzbuzz

if (Deno.args[0] == null) {
    console.error("No number specified, exiting.")
    Deno.exit(1)
}

const num = Number(Deno.args[0])
if (isNaN(num)) {
    console.error(
        `"${Deno.args[0]}" cannot be converted into a number, exiting.`)
    Deno.exit(1)
}

let output = ""

if (num % 3 == 0)
    output += "Fizz"

if (num % 5 == 0)
    output += "Buzz"

if (num == 0 || output == "")
    output = Deno.args[0]

console.log(output)
