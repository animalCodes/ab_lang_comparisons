package comparisons.kotlin.fizzbuzz

// Kotlin fizzbuzz

fun main(args: Array<String>) {
    if (args.size <= 0) {
        System.err.println("No number specified, exiting.")
        System.exit(1)
    }

    var input: Double? = args[0].toDoubleOrNull()
    if (input == null) {
        System.err.println(
            "\"${args[0]}\" cannot be converted into a number, exiting.")
        System.exit(1)
        return // So the compiler knows we won't be accessing a null value
    }

    val fizz = if (input % 3.0 == 0.0) "Fizz" else ""
    val buzz = if (input % 5.0 == 0.0) "Buzz" else ""
    var output = fizz+buzz

    if (output == "" || input == 0.0) output = args[0]

    println(output)
}
