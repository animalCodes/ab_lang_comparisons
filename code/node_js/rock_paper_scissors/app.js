const {argv, exit} = require("node:process")

// Node.js rock_paper_scissors

if (argv.length < 3) {
    console.error("No choice specified, exiting.")
    exit(1)
}

u_choice = argv[2].toLowerCase()

if (u_choice != "rock" && u_choice != "paper" && u_choice != "scissors") {
    console.error(`Invalid choice "${argv[2]}". Valid choices are "rock", `
        + '"paper" and "scissors". (All case-insensitive), exiting.')
    exit(1)
}

c_choice = Math.floor(Math.random() * 3)

if (c_choice == 0)
    c_choice = "rock"
else if (c_choice == 1)
    c_choice = "paper"
else
    c_choice = "scissors"

console.log(`User: ${u_choice}`)
console.log(`Computer: ${c_choice}`)

if (u_choice == c_choice)
    console.log("Tie!")
else if (c_choice == "rock" && u_choice == "paper"
        || c_choice == "paper" && u_choice == "scissors"
        || c_choice == "scissors" && u_choice == "rock")
    console.log("Winner: User!")
else
    console.log("Winner: Computer!")
