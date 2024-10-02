
// DenoJS is_prime

const input = Deno.args[0]

if (input == undefined) {
    console.error("No number specified, exiting.")
    Deno.exit(1)
}

const num = Number(input)
if (isNaN(num)) {
    console.error(`"${input}" cannot be converted into a number, exiting.`)
    Deno.exit(1)
}

if (!Number.isInteger(num)) {
    console.log("False")
    Deno.exit()
}

if (num < 2
    || num > 2 && num % 2 == 0
    || num > 3 && num % 3 == 0) {
    console.log("False")
    Deno.exit()
}

for (let i = 5; i*i <= num; i += 6) {
    if (num % i == 0 || num % (i+2) == 0) {
        console.log("False")
        Deno.exit()
    }
}

console.log("True")
