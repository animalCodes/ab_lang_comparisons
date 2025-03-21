# Rock paper scissors

CLI program for playing rock paper scissors against the computer.

The user will input their choice on execution, the program randomly generates its own choice and the two are compared to find a winner.

## Invocation

`rock_paper_scissors u_choice`

- `u_choice` - The user's choice, *should* be one of "rock", "paper" or "scissors" (case-insensitive).

### Examples

| Input                      | Output                                                                                                     |
| -------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `rock_paper_scissors foo`  | `Invalid choice "foo". Valid choices are "rock", "paper" and "scissors". (All case-insensitive), exiting.` |
| `rock_paper_scissors rock` | `User: rock` <br>`Computer: {choice}` <br>`Winner: {User\|Computer}!` OR `Tie!`                            |
| `rock_paper_scissors`      | `No choice specified, exiting.`                                                                            |

## Implementation

### Functions

- `random_choice()` - One of "rock", "paper" or "scissors", chosen randomly.

### Code

> Note: in below psuedo-code strings are treated as equal even if their cases differ.

```
if (!isset(u_choice)) {
    eprintln("No choice specified, exiting.")
    exit(1)
}

if (u_choice != "rock" && u_choice != "paper"
    && u_choice != "scissors) {
    eprintln("Invalid choice \"{u_choice}\". Valid choices are \"rock\", \"paper\" and \"scissors\". (All case-insensitive), exiting.")
    exit(1)
}

c_choice = random_choice()

println("User: {u_choice}")
println("Computer: {c_choice}")

if (c_choice == u_choice)
    println("Tie!")
else if (c_choice == "rock" && u_choice == "paper"
    || c_choice == "paper" && u_choice == "scissors"
    || c_choice == "scissors" &&  u_choice == "rock")
    println("Winner: User!")
else
    println("Winner: Computer!")
```

**Implemented in**: C, Java, Node.js, Python.

**To be implemented in**: C++, C#, DenoJS, Go, Kotlin, Ruby, Rust.
