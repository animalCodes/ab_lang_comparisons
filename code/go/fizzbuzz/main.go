package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
    if (len(os.Args) <= 1) {
        fmt.Println("No number specified, exiting")
        os.Exit(1)
    }
    
    // String conversion package - string to int
    // If we wanted to ignore the error, we would do `input, _ := ..`
	input, err := strconv.Atoi(os.Args[1])

    // Go uses `nil` instead of `null` because reasons.
	if err != nil {
		fmt.Println("An error occurred while converting input to a number: ", err)
        fmt.Println("Exiting.")
        os.Exit(2)
	}

	var output string = ""
	if input%3 == 0 {
		output += "Fizz"
	}
	if input%5 == 0 {
		output += "Buzz"
	}
	if input == 0 || output == "" {
		output = os.Args[1]
	}
	fmt.Println(output)
}
