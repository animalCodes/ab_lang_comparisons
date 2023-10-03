# Rock paper scissors

A command-line program where the user plays rock paper scissors with their computer.

The user will input their choice ("rock", "paper" or "scissors") as an argument when running the program which will then randomly generate its own choice, compare the two, and print the winner.

## Implementation

* Retrieve the user's choice. (Should be the first argument given to the program)
    * If no input was given, inform the user and exit.

* Check the input is actually a valid choice such as "rock", "paper", or "scissors". (Case-insensitive)
    * If it isn't, notify the user and exit after printing the valid options.

* Generate a random number to decide whether the computer's choice is `rock`, `paper` or `scissors`.
    * It should be noted that pseudo-random numbers are entirely acceptable, the only goal here is that the *human* user won't be able to accurately guess what the computer will choose.

* Print the user's and computer's choices.
    * Use the format `"{participant}: {choice}"` ie `"Computer: Scissors"`

* Compare the two choices and find the winner.
    * Use the format `"Winner: {Winner}!`", for instance `"Winner: Computer!"`
    * ...Unless it's a tie, in which case just print `"Tie!"`
    * Remember: Rock beats Scissors, Paper beats Rock, and Scissors beats Paper.

**Implemented in**: C.

**To be implemented in**: C++, C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
