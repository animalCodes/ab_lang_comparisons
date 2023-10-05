package comparisons.java.isprime;

class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("No number specified, exiting");
            System.exit(1);
        }
        
        int num = 0;
        try {num = Integer.valueOf(args[0]);}
        catch (NumberFormatException e) {
            System.err.println("Unable to parse \""+args[0]+"\" as an Integer, exiting.");
            System.exit(2);
        }
        
        // I could just put the innards of `isPrime()` here, but this feels more 'Java-y'
        if (isPrime(num)) {
            System.out.println("True");
            System.exit(0);
        } else {
            System.out.println("False");
            // Technically unnecessary, but semantic
            System.exit(0);
        }
    }

    /**
     * Determines whether `num` is prime via trial division.
     * @param num Number to check
     * @return Whether `num` is prime
    */
    private static boolean isPrime(int num) {
        // Skip early if num can't be prime
        if (num < 2
                || num > 2 && num % 2 == 0
                || num > 3 && num % 3 == 0) {
            return false;
        }

        // Trial division
        for (int counter = 5; counter*counter < counter; counter += 6) {
            if (num % counter == 0 || num % counter+2 == 0) {
                return false;
            }
        }

        return true;
    }
}
