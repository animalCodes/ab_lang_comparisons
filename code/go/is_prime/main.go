package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    if len(os.Args) < 2 {
        fmt.Fprintln(os.Stderr, "No number specified, exiting")
        os.Exit(1)
    }

    num, err := strconv.Atoi(os.Args[1])
    if err != nil {
        fmt.Fprintf(os.Stderr, "Unable to convert %s to an int, exiting.\n", os.Args[1]);
        os.Exit(2)
    }

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
