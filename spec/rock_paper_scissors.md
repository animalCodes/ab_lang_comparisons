# Rock paper scissors

CLI program for playing rock paper scissors against the computer.

The user will input their choice (via command-line argument) on execution, the program randomly generates it's own choice and the two are compared to find a winner.

## Implementation

* Retrieve the user's choice. (Should be the first argument given to the program)
    * If no input was given, inform the user and exit.

* Check the input is actually a valid choice such as "rock", "paper", or "scissors". (Case-insensitive)
    * If it isn't, print the valid options and exit.

Randomly choose rock, paper or scissors as the computer's choice.
It should be noted that pseudo-random choice selection is entirely acceptable, the only goal here is that the *human* user won't be able to accurately guess what the computer will choose.

* Print the user's and computer's choices.
    * Use the format "{player}: {choice}" ie "Computer: Scissors"

* Compare the two choices and print the winner.
    * Use the format "Winner: {Winner}!", for instance "Winner: Computer!"
    * ...Unless it's a tie, in which case just print "Tie!"

**Implemented in**: C.

**To be implemented in**: C++, C#, DenoJS, Go, Java, Kotlin, Node.js, Ruby, Rust.
