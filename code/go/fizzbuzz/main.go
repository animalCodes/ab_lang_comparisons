package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
    if len(os.Args) <= 1 {
        fmt.Fprintln(os.Stderr, "No number specified, exiting.\n")
        os.Exit(1)
    }

    // If we wanted to ignore the error, we would do `input, _ := ..`
    input, err := strconv.Atoi(os.Args[1])

    if err != nil {
        fmt.Fprintf(os.Stderr,
            "%s cannot be converted into a number, exiting.\n", os.Args[1])
        os.Exit(1)
    }

    var output = ""
    if input % 3 == 0 {
        output += "Fizz"
    }
    if input % 5 == 0 {
        output += "Buzz"
    }
    if input == 0 || output == "" {
        output = os.Args[1]
    }

    fmt.Println(output)
}
