package comparisons.java.sqrt;

// Java sqrt

public class Main {
    public static void main(String[] args) {
        Double square = Double.NaN;
        if (args.length >= 1) {
            try {
                square = Double.valueOf(args[0]);
            } catch (NumberFormatException e) {}
        }

        if (square == 0) {
            System.out.println(String.format("%.5f", square));
            System.exit(0);
        } else if (square.isNaN() || square < 0
            || square == Double.POSITIVE_INFINITY) {
            System.out.println("NaN");
            System.exit(0);
        }

        System.out.println(String.format("%.5f", sqrt(square)));
    }

    /**
     * Calculate square root of `n` to 5 decimal digits of precision.
     *
     * @param n Square number.
     * @return Approximate square root of `n`.
     */
    private static double sqrt(double n) {
        double prev, guess = 1;
        while (true) {
            prev = Math.floor(guess);
            guess = (guess + (n / guess)) / 2;
            if (prev == Math.floor(guess))
                break;
        }

        guess = (guess + (n / guess)) / 2;
        guess = (guess + (n / guess)) / 2;

        return guess;
    }
}

