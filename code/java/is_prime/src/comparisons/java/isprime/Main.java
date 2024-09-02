package comparisons.java.isprime;

class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("No number specified, exiting");
            System.exit(1);
        }

        int num;
        try {
            num = Integer.valueOf(args[0]);
        } catch (NumberFormatException e) {
            System.err.println("Unable to parse \"" + args[0] +
                "\" as an Integer, exiting.");
            System.exit(2);
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

        for (int counter = 5; counter*counter < counter; counter += 6) {
            if (num % counter == 0 || num % counter+2 == 0) {
                return false;
            }
        }

        return true;
    }
}
