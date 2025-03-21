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

let key = Number(argv[2])

if (isNaN(key) || Math.floor(key) != key) {
    console.error(`"${argv[2]}" isn't an integer, exiting.`)
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
