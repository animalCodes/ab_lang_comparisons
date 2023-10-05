package comparisons.java.fizzbuzz;

class Main {
    public static void main(String[] args) {
        if (args.length <= 0) {
            System.err.println("No number specified, exiting");
            System.exit(1);
        }

        int num = 0;
        try {
            num = Integer.valueOf(args[0]);
        } catch (NumberFormatException e) {
            System.err.println("Unable to parse \"" + args[0] + "\" as an integer, exiting.");
            System.exit(2);
        }

        String out = "";
        if (num % 3 == 0)
            out += "Fizz";
        if (num % 5 == 0)
            out += "Buzz";
        if (num == 0 || out == "")
            out = String.valueOf(num);

        System.out.println(out);
    }
}
