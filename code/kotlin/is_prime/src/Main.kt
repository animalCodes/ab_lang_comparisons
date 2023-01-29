package comparisons.kotlin.isprime

/**
 * Checks all possible factors of `input` between 1 and input-1, returning true if none exist
 */
tailrec fun checkFactors(input: Int, fact: Int): Boolean {
    // Kotlin specifically has supprt for recursive functions, so may as well use one.
    if (fact < 2) return true
    else if (input % fact == 0) return false
    else return checkFactors(input, fact-1)
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

    // No prime numbers < 2 exist, so exit early if inputted number is so.
    if (input < 2) {
        println("False")
        System.exit(0)
    }

    // Check every number between 1 and input-1
    if (checkFactors(input, input-1)) {
        println("True")
        System.exit(0)
    } else {
        println("False")
        System.exit(0)
    }
}

