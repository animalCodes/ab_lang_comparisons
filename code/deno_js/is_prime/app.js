// Get input, check it exists
const input = Deno.args[0]
if (input == undefined) {
    console.log("No input received, exiting")
    Deno.exit(1)
}
// Convert to Number
const num = Number(input)
if (isNaN(num)) {
    console.log(`Unable to convert "${input}" to a number, exiting.`)
    Deno.exit(2)
}
// Don't bother looping if we know the number can't be prime.
if (num < 2) {
    console.log("False")
    Deno.exit()
}
// Check for "primeness"
let divisor = num-1
// `for` expressions are optional
for (; divisor > 1; divisor--) {
    if (num % divisor == 0) {
        console.log("False")
        Deno.exit()
    }
}
// If we get this far, number must be prime.
console.log("True")
