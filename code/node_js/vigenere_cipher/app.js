const {argv, exit, stdin, stdout} = require("node:process")
const {createInterface} = require("node:readline")

// Node.js vigenere_cipher

const alphabet = "abcdefghijklmnopqrstuvwxyz"

if (argv.length < 3) {
    console.error("No message given, exiting.")
    exit(1)
}

argv[0] = undefined
argv[1] = undefined
const plaintext = argv.join(" ").trim().toLowerCase()

const rl = createInterface({input: stdin, output: stdout})
rl.question("Enter key: ", key => {
    rl.close()
    if (key.length == 0) {
        console.error("No key given, exiting.")
        exit(1)
    }

    if (!alphabetical(key)) {
        console.error("Key contains non-alphabetical characters, exiting.")
        exit(1)
    }

    console.log(encipher(plaintext, key))
})

function encipher(plaintext, key) {
    let message = ""

    let k = 0;
    for (const char of plaintext) {
        let j = alphabet.indexOf(char)
        if (j == -1) {
            message += char
            continue
        }

        j += alphabet.indexOf(key.at(k))
        j %= 26
        message += alphabet.at(j)

        if (++k >= key.length)
            k = 0
    }

    return message
}

function alphabetical(str) {
    for (const c of str) {
        if (!alphabet.includes(c))
            return false
    }
    return true
}
