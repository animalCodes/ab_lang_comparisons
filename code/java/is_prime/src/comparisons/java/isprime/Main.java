package comparisons.java.isprime;

// Java is_prime

class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("No number specified, exiting.");
            System.exit(1);
        }

        Float input;
        try {
            input = Float.valueOf(args[0]);
        } catch (NumberFormatException e) {
            System.err.println('"' + args[0] +
                "\" cannot be converted into a number, exiting.");
            System.exit(1);
            return;
        }

        int num = input.intValue();

        if (input != num) {
            System.err.println("False");
            return;
        }

        if (isPrime(num))
            System.out.println("True");
        else
            System.out.println("False");
    }

    /**
     * Whether `num` is prime.
     *
     * @param num Number to check.
     * @return Whether `num` is prime.
    */
    private static boolean isPrime(int num) {
        if (num < 2
                || num > 2 && num % 2 == 0
                || num > 3 && num % 3 == 0) {
            return false;
        }

        for (int counter = 5; counter*counter < num; counter += 6) {
            if (num % counter == 0 || num % counter+2 == 0) {
                return false;
            }
        }

        return true;
    }
}
