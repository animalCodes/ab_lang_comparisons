package comparisons.java.caesarcipher;

// Java caesar_cipher

class Main {
    private static final String alphabet = "abcdefghijklmnopqrstuvwxyz";

    public static void main(String[] args) {
        if (args.length < 2) {
            if (args.length < 1)
                System.err.println("No shift or message given, exiting.");
            else
                System.err.println("No message given, exiting.");
            System.exit(1);
        }

        int key = 0;
        try {
            key = Integer.valueOf(args[0]);
        } catch (NumberFormatException e) {
            System.err.println("\""+args[0]+"\" isn't an integer, exiting.");
            System.exit(1);
        }

        StringBuilder builder = new StringBuilder();
        for (int i = 1; i < args.length; i++)
            builder.append(args[i]);

        char[] message = builder.toString().toCharArray();

        for (int i = 0; i < message.length; i++)
            message[i] = shift(message[i], key);

        System.out.println(message);
    }

    /**
     * Return `c` shifted `key` places.
     *
     * If `c` is a non-alphabetical character, return `c`.
     *
     * @param c Character to shift.
     * @param key Number of places to shift, may be negative.
     * @return `c` enciphered with key `key`.
     */
    private static char shift(char c, int key) {
        key = normalise(key);

        int index = alphabet.indexOf(c);
        if (index == -1)
            return c;

        return alphabet.charAt(index + key);
    }

    /**
     * Return `key` normalised to be a valid index into `alphabet`.
     *
     * @param key Original key.
     * @return Normalised key.
     */
    private static int normalise(int key) {
        key %= alphabet.length();
        if (key < 0)
            key += alphabet.length();
        return key;
    }
}

