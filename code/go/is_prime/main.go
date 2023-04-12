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

    // Exit early if num can't be prime
    if num < 2 || num > 2 && num % 2 == 0 || num > 3 && num % 3 == 0 {
        fmt.Println("False")
        os.Exit(0)
    }

    for i := 5; i*i < num; i += 6 {
        if num % i == 0 || num % i+2 == 0 {
            fmt.Println("False")
            os.Exit(0)
        }
    }

    fmt.Println("True")
}
