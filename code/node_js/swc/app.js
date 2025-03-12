const {createReadStream} = require("node:fs")
const {argv, exit} = require("node:process")
const {parseArgs} = require("node:util")

// Node.js swc

const helpMessage = "Usage: swc [options] file\n"+
"Print newline, word and byte counts for file. A word is a sequence of\n"+
"non-whitespace delimited by whitespace or start/end of input.\n\n"+
"The options below may be used to select which counts are printed, always "+
"in the\nfollowing order: newline, word, byte.\n"+
"  -c  print byte count.\n"+
"  -l  print newline count.\n"+
"  -w  print word count.\n"+
"  -h  display this help and exit."

const options = {
    newline: {
        type: "boolean",
        short: "l"
    },
    word: {
        type: "boolean",
        short: "w"
    },
    byte: {
        type: "boolean",
        short: "c"
    },
    help: {
        type: "boolean",
        short: "h"
    }
}

const {values, positionals} = parseArgs({options, strict: false})

if (values.help) {
    console.log(helpMessage)
    exit(0)
}

if (positionals.length == 0) {
    console.error("No file specified, exiting.")
    exit(1)
}

for (opt in values) {
    if (opt != "newline" && opt != "word" && opt != "byte"
        && opt != "help") {
        console.error(`Invalid option "${opt}", try "swc -h" for help.`)
        exit(1)
    }
}

if (!values.newline && !values.word && !values.byte) {
    values.newline = true
    values.word = true
    values.byte = true
}

let l = 0
let w = 0
let c = 0

const stream = createReadStream(positionals[0], {encoding: "UTF-8"})

stream.on("data", (chunk) => {
    l += countChars(chunk, '\n')
    w += countWords(chunk)
    c += chunk.length
})

stream.on("end", () => {
    let message = ""

    if (values.newline) {
        message += l
    }

    if (values.word) {
        if (message.length > 0)
            message += " "
        message += w
    }

    if (values.byte) {
        if (message.length > 0)
            message += " "
        message += c
    }

    console.log(message)
})

stream.on("error", () => {
    console.error(`Cannot access file "${positionals[0]}"`)
    exit(1)
})

function countWords(str) {
    let count = 0
    let space = true

    for (char of str) {
        if (char == " " || char == "\t" || char == "\n" || char == "\r"
            || char == "\f")
            space = true
        else if (space) {
            count++
            space = false
        }
    }
    return count
}

function countChars(str, char) {
    let count = 0;
    for (let i = 0; i < str.length; i++) {
        if (str[i] == char)
            count++
    }
    return count
}
