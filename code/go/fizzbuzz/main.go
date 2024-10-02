package main

// Go fizzbuzz

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    if len(os.Args) <= 1 {
        fmt.Fprintln(os.Stderr, "No number specified, exiting.")
        os.Exit(1)
    }

    input, err := strconv.ParseFloat(os.Args[1], 64)

    if err != nil {
        fmt.Fprintf(os.Stderr,
            "\"%s\" cannot be converted into a number, exiting.\n", os.Args[1])
        os.Exit(1)
    }

    if (math.Trunc(input) != input) {
        fmt.Println(input)
        os.Exit(1)
    }

    var num int = int(input)

    var output = ""
    if num % 3 == 0 {
        output += "Fizz"
    }
    if num % 5 == 0 {
        output += "Buzz"
    }
    if num == 0 || output == "" {
        output = os.Args[1]
    }

    fmt.Println(output)
}
