const input = Deno.args[0]

if (input == undefined) {
    console.log("No input received, exiting")
    Deno.exit(1)
}

const num = Number(input)
if (isNaN(num)) {
    console.log(`Unable to convert "${input}" to a number, exiting.`)
    Deno.exit(2)
}

// Don't bother looping if we know the number can't be prime.
if (num < 2
    || num > 2 && num % 2 == 0
    || num > 3 && num % 3 == 0) {
    console.log("False")
    Deno.exit()
}

// Try trial division
for (let i = 5; i*i < num; i += 6) {
    if (num % i == 0 || num % (i+2) == 0) {
        console.log("False")
        Deno.exit()
    }
}

// If we get this far, number must be prime.
console.log("True")
