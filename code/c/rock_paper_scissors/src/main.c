#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // For strcasecmp()
#include <time.h> // For time_t and time()

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "No argument specified, exiting.\n");
        return 1;
    }

    char *user_input = argv[1];
    // On a pedantic note this variable will only ever use a maximum of 2 bits, (2, the 
    // maximum possible value, would be represented as `10`) so using a short (which is 
    // *usually* comprised of 2 bytes) is technically wasting 14 bits.
    short user_choice;

    if (!strcasecmp(user_input, "rock"))
        // Store a numerical representation of the choice to simplify later comparisons
        user_choice = 0;
    else if (strcasecmp(user_input, "paper") == 0)
        user_choice = 1;
    else if (strcasecmp(user_input, "scissors") == 0)
        user_choice = 2;
    else {
        fprintf(stderr, "Invalid choice \"%s\", valid inputs are \"rock\", \"paper\" and \"scissors\" (all case-insensitive), Exiting.\n", user_input);
        return 2;
    }

    time_t now;
    time(&now); // Store current timestamp in `now`
    srand(now); // Seed the pseudo-random number generator with the current time

    // This mess converts the output of `rand()` (which returns any value between 0 and `RAND_MAX`) to 0, 1, or 2.
    // Firstly, it divides the output of `rand()` by `RAND_MAX`, this'll give us a decimal number such as 0.468722.
    // (Notice they are first cast to floats, if we didn't do this the result of the divison would be automatically converted to an integer, which would defeat the entire point.)
    // Now we have a random decimal number with a max value of 1, but we want the end number to be 0, 1 or 2. This conversion can be done by multiplying the decimal by the greatest number + 1, in this case we multiply by 3.
    // Finally, the result is cast to a short to discard the now-useless decimal precision. (Doing so also makes comparing against the user's choice much easier)
    // TODO make this easier to read
    short computer_choice = (short)(((float)rand() / (float)RAND_MAX) * 3);

    printf("User: %s\n", user_input);

    // Printing the computer's choice is a little bit more complicated as we only have a numerical representation
    printf("Computer: ");
    if (computer_choice==0)
        printf("Rock\n");
    else if (computer_choice==1)
        printf("Paper\n");
    else
        printf("Scissors\n");

    if (computer_choice == user_choice)
        printf("Tie!\n");
    // 0 = Rock, 1 = Paper, 2 = Scissors.
    else if ((computer_choice == 0 && user_choice == 1) ||
            (computer_choice == 1 && user_choice == 2) ||
            (computer_choice == 2 && user_choice == 0))
        printf("Winner: User!\n");
    else
        printf("Winner: Computer!\n");

    return 0;
}
