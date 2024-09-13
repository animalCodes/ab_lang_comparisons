package comparisons.kotlin.isprime

fun main(args: Array<String>) {
    if (args.size <= 0) {
        System.err.println("No number specified, exiting.")
        System.exit(1)
    }

    val input: Float? = args[0].toFloatOrNull()
    if (input == null) {
        System.err.println(
            "\"${args[0]}\" cannot be converted into a number, exiting.")
        System.exit(1)
        return
    }

    val num: Int = input.toInt()
    if (input != num) {
        println("False")
        return
    }

    if (num < 2
        || num > 2 && num % 2 == 0
        || num > 3 && num % 3 == 0) {
        println("False")
        return
    }

    // We could use a range here to generate the sequence, but that would
    // require calculating the square root of `input`.
    var i = 5
    while (i * i < num) {
        if (num % i == 0 || num % i+2 == 0) {
            println("False")
            return
        }
        i += 6
    }

    println("True")
}

