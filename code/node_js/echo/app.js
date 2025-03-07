const {argv, exit} = require("node:process")

// Node.js echo

let message = ""

for (let i = 2; i < argv.length-1; i++)
    message += argv[i] + " "
message += argv[argv.length-1]

console.log(message)
