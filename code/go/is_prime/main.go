package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Check input is given
    if len(os.Args) < 2 {
        fmt.Println("No number specified, exiting")
        os.Exit(1)
    }

    // Attempt to convert to int
    num, err := strconv.Atoi(os.Args[1])
    if err != nil {
        fmt.Printf("Unable to convert %s to an int, exiting.\n", os.Args[1]);
        os.Exit(2)
    }

    // Exit early if num < 2
    if num < 2 {
        fmt.Println("False")
        os.Exit(0)
    }

    comp := num-1 // "COMPare"
    // Go only has a `for` loop construct, but it can double as a while loop.
    for ; comp > 1; comp-- {
        if (num % comp == 0) {
            fmt.Println("False")
            os.Exit(0)
        }
    }

    fmt.Println("True")
}
