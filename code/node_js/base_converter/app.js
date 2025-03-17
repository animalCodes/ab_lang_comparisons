const {argv, exit} = require("node:process")

// Node.js base_converter

if (argv.length < 4) {
    if (argv.length < 3)
        console.error("No base or number specified, exiting.")
    else
        console.error("No number specified, exiting.")
    exit(1)
}

const n = Math.floor(Number(argv[3]))

if (isNaN(n)) {
    console.error(`"${argv[3]}" isn't a decimal integer, exiting.`)
    exit(1)
}

const base = Number(argv[2])

switch (base) {
    case 2: {
        console.log(n.toString(2))
        break
    }
    case 8: {
        console.log(n.toString(8))
        break
    }
    case 16: {
        console.log(n.toString(16).toUpperCase())
        break
    }
    default: {
        console.error("Base must be 2, 8, or 16, exiting.")
        exit(1)
    }
}
