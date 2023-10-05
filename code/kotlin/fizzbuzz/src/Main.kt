package comparisons.kotlin.fizzbuzz

fun main(args: Array<String>) {
    if (args.size <= 0) {
        println("No number specified, exiting.")
        System.exit(1)
    }

    var input: Int? = args[0].toIntOrNull()
    if (input == null) {
        println("Unable to convert \"${args[0]}\" to a number, exiting.")
        System.exit(2)
        return // So the compiler knows we won't be accessing a null value
    }

    // In Kotlin, if statements double as expressions, essentially acting as ternary operators.
    val fizz = if (input % 3 == 0) "Fizz" else ""
    val buzz = if (input % 5 == 0) "Buzz" else ""
    var output = fizz+buzz

    if (output == "" || input == 0) output = args[0]

    println(output)
}
