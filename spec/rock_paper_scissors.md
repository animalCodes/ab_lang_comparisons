# Rock paper scissors

CLI program for playing rock paper scissors against the computer.

The user will input their choice on execution, the program randomly generates its own choice and the two are compared to find a winner.

### Invocation

`rock_paper_scissors u_choice`

- `u_choice` - The user's choice, *should* be one of "rock", "paper" or "scissors" (case-insensitive).

### Examples

| Input                      | Output                                                                                                     |
| -------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `rock_paper_scissors`      | `No choice specified, exiting.`                                                                            |
| `rock_paper_scissors foo`  | `Invalid choice "foo", valid choices are "rock", "paper" and "scissors". (All case-insensitive), exiting.` |
| `rock_paper_scissors rock` | `User: rock` <br>`Computer: {choice}` <br>`Winner: {User OR Computer}!`                                    |

## Implementation

### Functions

- `print_err(str)` - Send `str` to stderr with a trailing newline.

- `print(str)` - Send `str` to stdout with a trailing newline.

- `random_choice()` - One of "rock", "paper" or "scissors", chosen randomly.

- `exit(code)` - Terminate program with exit code `code`.

### Code

> Note: in this psuedo-code strings are treated as equal even if their cases differ.

```
if (u_choice == null) {
    print_err("No choice specified, exiting.")
    exit(1)
}

if (u_choice != "rock" && u_choice != "paper"
    && u_choice != "scissors) {
    print_err("Invalid choice \"%s\", valid choices are \"rock\", \"paper\" and \"scissors\". (All case-insensitive), exiting.)
    exit(1)
}

c_choice = random_choice()

print("User: %s", u_choice)
print("Computer: %s", c_choice)

if (c_choice == u_choice)
    print("Tie!")
else if (c_choice == "rock" && u_choice == "paper"
    || c_choice == "paper" && u_choice == "scissors"
    || c_choice == "scissors" &&  u_choice == "rock")
    print("Winner: User!")
else
    print("Winner: Computer!")
```

**Implemented in**: C.

**To be implemented in**: C++, C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
