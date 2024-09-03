package comparisons.kotlin.isprime

fun main(args: Array<String>) {
    if (args.size <= 0) {
        System.err.println("No number specified, exiting.")
        System.exit(1)
    }

    val input: Int? = args[0].toIntOrNull()
    if (input == null) {
        System.err.println(
            "Unable to convert \"${args[0]}\" to a number, exiting.")
        System.exit(2)
        return
    }

    if (input < 2
        || input > 2 && input % 2 == 0
        || input > 3 && input % 3 == 0) {
        println("False")
        return
    }

    // We could use a range here to generate the sequence, but that would
    // require calculating the square root of `input`.
    var i = 5
    while (i * i < input) {
        if (input % i == 0 || input % i+2 == 0) {
            println("False")
            return
        }
        i += 6
    }

    println("True")
}

