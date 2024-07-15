#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // For strcasecmp()
#include <time.h> // For time_t and time()

typedef enum Choice {
    ROCK,
    PAPER,
    SCISSORS,
    NONE
} Choice;

/* Convert input string to Choice.
    if input is invalid, NONE will be returned. */
Choice strchoice(char *input);

/* Convert Choice to string.
    ROCK = "rock"
    PAPER = "paper"
    SCISSORS = "scissors"
    NONE = "" */
char *choicestr(Choice choice);

/* Randomly return one of ROCK, PAPER or SCISSORS. */
Choice randchoice();

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "No argument specified, exiting.\n");
        return EXIT_FAILURE;
    }

    char *user_input = argv[1];
    Choice user_choice = strchoice(user_input);
    if (user_choice == NONE) {
        fprintf(stderr, "Invalid choice \"%s\", valid inputs are \"rock\""
                "\"paper\" and \"scissors\" (all case-insensitive), Exiting.\n",
                user_input);
        return EXIT_FAILURE;
    }

    Choice computer_choice = randchoice();

    printf("User: %s\n", user_input);
    printf("Computer: %s\n", choicestr(computer_choice));

    if (computer_choice == user_choice)
        printf("Tie!\n");
    else if ((computer_choice == ROCK && user_choice == PAPER) ||
            (computer_choice == PAPER && user_choice == SCISSORS) ||
            (computer_choice == SCISSORS && user_choice == ROCK))
        printf("Winner: User!\n");
    else
        printf("Winner: Computer!\n");

    return EXIT_SUCCESS;
}

Choice strchoice(char *input)
{
    if (!strcasecmp(input, "rock"))
        return ROCK;
    else if (!strcasecmp(input, "paper"))
        return PAPER;
    else if (!strcasecmp(input, "scissors"))
        return SCISSORS;
    else
        return NONE;
}

char *choicestr(Choice choice)
{
    switch (choice) {
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        default:
            return "";
    }
}

Choice randchoice()
{
    // I've just realised these three lines have the exact same length, this
    // makes me happy
    time_t now;
    time(&now);
    srand(now);

    // This mess converts the output of `rand()` (which returns any value
    // between 0 and `RAND_MAX`) to 0, 1, or 2.
    return (Choice)(((float)rand() / (float)RAND_MAX) * 3);
}
