const {argv, exit} = require("node:process")

// Node.js caesar_cipher

const alphabet = "abcdefghijklmnopqrstuvwxyz"

if (argv.length < 3) {
    console.error("No shift or message given, exiting.")
    exit(1)
}

if (argv.length < 4) {
    console.error("No message given, exiting.")
    exit(1)
}

let key = Math.floor(Number(argv[2]))

if (isNaN(key)) {
    console.error(`Couldn't convert "${argv[2]}" to an integer, exiting.`)
    exit(1)
}

let plaintext = argv[3]
for (let i = 4; i < argv.length; i++)
    plaintext += " "+argv[i]
plaintext = plaintext.toLowerCase()

message = ""
for (const char of plaintext[Symbol.iterator]()) {
    let index = alphabet.indexOf(char)
    if (index == -1) {
        message += char
        continue
    }

    index += key
    index %= 26

    message += alphabet.at(index)
}

console.log(message)
