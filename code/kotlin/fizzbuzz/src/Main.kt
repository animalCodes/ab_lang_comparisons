package comparisons.kotlin.fizzbuzz

fun main(args: Array<String>) {
    if (args.size <= 0) {
        println("No number specified, exiting.")
        System.exit(1)
    }

    var input: Int? = args[0].toIntOrNull()
    if (input == null) {
        // Kotlin **really** tries to avoid NullPointerExceptions, which is a bit 
        // inconvenient in this case as the compiler doesn't realise that we are
        // specifically checking for whether input is null and exiting if it is.
        // The workaround is to set input to any none-null value, this way the
        // compiler will know for sure it won't be null, and allow the below checks.
        input = 0
        println("Unable to convert \"${args[0]}\" to a number, exiting.")
        System.exit(2)
    }

    // In Kotlin, if statements double as expressions, essentially acting as ternary operators.
    val fizz = if (input % 3 == 0) "Fizz" else ""
    val buzz = if (input % 5 == 0) "Buzz" else ""
    var output = fizz+buzz

    // If neither divisible by 3 or 5, or if input is zero, print given number 
    if (output == "" || input == 0) output = args[0]
    println(output)
}
