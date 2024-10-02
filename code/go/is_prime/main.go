package main

// Go is_prime

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    if len(os.Args) < 2 {
        fmt.Fprintln(os.Stderr, "No number specified, exiting.")
        os.Exit(1)
    }

    n, err := strconv.ParseFloat(os.Args[1], 64)
    if err != nil {
        fmt.Fprintf(os.Stderr,
            "\"%s\" cannot be converted into a number, exiting.\n", os.Args[1])
        os.Exit(1)
    }

    if (n != math.Floor(n)) {
        fmt.Println("False")
        os.Exit(0)
    }

    // The remainder operator (%) is only defined for integers.. Because reasons
    var m = int(n)

    if m < 2 || m > 2 && m % 2 == 0 || m > 3 && m % 3 == 0 {
        fmt.Println("False")
        os.Exit(0)
    }

    for i := 5; i*i <= m; i += 6 {
        if m % i == 0 || m % i+2 == 0 {
            fmt.Println("False")
            os.Exit(0)
        }
    }

    fmt.Println("True")
}
