package comparisons.java.rockpaperscissors;

// Java rock_paper_scissors

class Main {
    public static void main(String[] args) {
        if (args.length <= 0) {
            System.err.println("No choice specified, exiting");
            System.exit(1);
        }

        Choice userChoice = Choice.toChoice(args[0]);

        if (userChoice == null) {
            System.err.println("Invalid choice \"" + args[0] +
                "\", valid choices are \"rock\", \"paper\" and \"scissors\". "
                + "(All case-insensitive), exiting.");
            System.exit(1);
        }

        Choice computerChoice = Choice.pickRandom();

        System.out.println("User: " + userChoice);
        System.out.println("Computer: " + computerChoice);

        if (computerChoice == userChoice)
            System.out.println("Tie!");
        else if ((userChoice == Choice.PAPER && computerChoice == Choice.ROCK)
            || (userChoice == Choice.SCISSORS && computerChoice == Choice.PAPER)
            || (userChoice == Choice.ROCK && computerChoice == Choice.SCISSORS))
            System.out.println("Winner: User!");
        else
            System.out.println("Winner: Computer!");
    }

    private enum Choice {
        ROCK("rock"),
        PAPER("paper"),
        SCISSORS("scissors");

        private final String string;

        Choice(String string) {
            this.string = string;
        }

        /**
         * Convert string choice to Choice.
         *
         * @param string String to convert.
         * @return Choice or null if string is invalid.
         */
        public static Choice toChoice(String string) {
            if (string.compareToIgnoreCase("rock") == 0)
                return ROCK;
            else if (string.compareToIgnoreCase("paper") == 0)
                return PAPER;
            else if (string.compareToIgnoreCase("scissors") == 0)
                return SCISSORS;
            else
                return null;
        }

        /**
         * One of ROCK, PAPER or SCISSORS. Chosen randomly.
         *
         * @return Random choice.
         */
        public static Choice pickRandom() {
            int n = (int)(Math.random() * 3);
            switch (n) {
                case 0:
                    return Choice.ROCK;
                case 1:
                    return Choice.PAPER;
                default:
                    return Choice.SCISSORS;
            }
        }

        public String toString() {
            return this.string;
        }
    }
}

