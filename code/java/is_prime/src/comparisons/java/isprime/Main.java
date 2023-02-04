package comparisons.java.isprime;

class Main {
    public static void main(String[] args) {
        // Check input exists
        if (args.length < 1) {
            System.err.println("No number specified, exiting");
            System.exit(1);
        }
        
        // Attempt to convert to int
        int num = 0;
        try {num = Integer.valueOf(args[0]);}
        catch (NumberFormatException e) {
            System.err.println("Unable to parse \""+args[0]+"\" as an Integer, exiting.");
            System.exit(2);
        }
        
        // Skip early if num can't be prime
        if (num < 2) {
            System.out.println("False");
            System.exit(0);
        }

        // Check all numbers between num-1 and 1
        for (int divisor = num-1; divisor > 1; divisor--) {
            if (num % divisor == 0) {
                System.out.println("False");
                System.exit(0);
            }
        }

        System.out.println("True");
    }
}
