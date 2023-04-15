package comparisons.kotlin.isprime

/**
 * A recursive implementation of trial division
 * @param input Number we are trying to figure out if prime
 * @param counter Counter variable, primarily for recursion
 * @return Whether `input` is prime
 */
tailrec fun recursiveTrialDivision(input: Int, counter: Int): Boolean {
    // Kotlin specifically has support for recursive functions, so we may as well use one.
    if (counter*counter >= input) return true
    else if (input % counter == 0 || input % counter+2 == 0) return false
    else return recursiveTrialDivision(input, counter+6)
}

fun main(args: Array<String>) {
    // Check input exists
    if (args.size <= 0) {
        println("No number specified, exiting.")
        System.exit(1)
    }

    // Confirm input is valid
    val input: Int? = args[0].toIntOrNull()
    if (input == null) {
        println("Unable to convert \"${args[0]}\" to a number, exiting.")
        System.exit(2)
        return // Return so the compiler knows we won't be accessing a null value.
    }

    // If input is less than 2, greater than 2 and divisible by 2, or greater than 3 and divisible by 3.
    if (input < 2 || input > 2 && input % 2 == 0 || input > 3 && input % 3 == 0) {
        println("False")
        System.exit(0)
    }

    // Finally, try trial division
    if (recursiveTrialDivision(input, 6)) {
        println("True")
        System.exit(0)
    } else {
        println("False")
        System.exit(0)
    }
}

