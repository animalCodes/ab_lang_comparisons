package comparisons.java.fizzbuzz;

class Main {
    public static void main(String[] args) {
        // Check number is specified
        if (args.length <= 0) {
            // By default `System.err` will act the same as `System.out`,
            // but this feels more semantic.
            System.err.println("No number specified, exiting");
            System.exit(1);
        }
        // Check number is actually a number
        int num = 0;
        try {num = Integer.valueOf(args[0]);} 
        catch (NumberFormatException e) {
            System.err.println("Unable to parse \""+args[0]+"\" as an integer, exiting.");
            System.exit(2);
        }

        String out = "";
        // So in Java if the code block to run is a single line you can 
        // omit the braces, this is generally considered bad practice but 
        // I thought I'd show it off anyway.
        if (num % 3 == 0)
            out += "Fizz";
        if (num % 5 == 0)
            out += "Buzz";
        if (num == 0 || out == "")
            out = String.valueOf(num);
    
        System.out.println(out);
    }  
}
